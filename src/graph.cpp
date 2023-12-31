//Gaspard Gentil

#include "graph.hpp"
#include <queue>
#include <algorithm>

Graph::Graph() : L(0), C(0) {
    pixels = new Pixel[L * C];
    S.setIntensity(255);
    T.setIntensity(0);
}

Graph::Graph(std::string filename) {
    std::ifstream in(filename);
    if (!in.is_open()) {
        throw std::runtime_error("Error: Unable to open file " + filename);
    }

    std::string magic;
    in >> magic;
    if (magic != "P2") {
        in.close();
        throw std::runtime_error("Error: Invalid magic number in file " + filename);
    }
    
    if (!(in >> L >> C)) {
        in.close();
        throw std::runtime_error("Error: Invalid dimensions in file " + filename);
    }

    pixels = new Pixel[L * C];
    int temp;
    for (int i = 0; i < L * C; i++) {
        if (!(in >> temp)) {
            delete[] pixels;
            in.close();
            throw std::runtime_error("Error: Unable to read pixel value from file " + filename);
        }
        pixels[i].setIntensity(temp);
    }
    in.close();
    S.setIntensity(255);
    T.setIntensity(0);
}

Graph::~Graph() {
    delete[] pixels;
}

void Graph::initializeGraph() {
    for (int i = 0; i < L * C; i++) {
        pixels[i].setState(0);

        // Set the flow to 0 for all directions
        for (int dir = 0; dir < 4; dir++) {
            pixels[i].flow[dir] = 0;
        }

        // Set capacity using nearCap for arcs towards neighbors (North, South, East, West)
        nearCap(i);
    }
}

int Graph::pixel(const int l, const int c){
    return pixel(index(l,c));
}

int Graph::pixel(const int i){
    assert(i >= 0);
    assert(i < L * C);
    return pixels[i].getIntensity();
}

int Graph::index(const int l, const int c){
    return l*C +c;
}
int Graph::line(const int i){
    return i / C;
}
int Graph::column(const int i){
    return i % C;
}

bool Graph::exists(const int l, const int c){
    if (l < 0) return false;
    if (l >= L) return false;
    if (c < 0) return false;
    if (c >= C) return false;
    return true;
}

int Graph::near(const int l, const int c, int lines[4], int columns[4]){
    int n = 0;
    if (exists(l + 1, c)){ // voisin du haut
        lines[n] = l + 1;
        columns[n] = c;
        n++;
    }

    if (exists(l - 1, c)){ // voisin du bas
        lines[n] = l - 1;
        columns[n] = c;
        n++;
    }

    if (exists(l, c - 1)){ // voisin de gauche
        lines[n] = l;
        columns[n] = c - 1;
        n++;
    }

    if (exists(l, c + 1)){ // voisin de droite
        lines[n] = l;
        columns[n] = c + 1;
        n++;
    }
    return n;
}

void Graph::nearCap(const int i) {
    int l = line(i);
    int c = column(i);

    int lines[4];
    int columns[4];
    int n = near(l, c, lines, columns);

    for (int v = 0; v < n; ++v) {
        int neighborIndex = index(lines[v], columns[v]);
        
        // Calculating the capacity array following the formula
        double intensityDifference = pixels[i].getIntensity() - pixels[neighborIndex].getIntensity();
        double capacityValue = H* std::exp(-(intensityDifference * intensityDifference) / (2 * SIGMA * SIGMA));

        pixels[i].capacity[v] = capacityValue;
    }

     // Initializing the source and sink capacity following the formulas
    double sourceCapacity = -ALPHA * log((255.0 - pixels[i].getIntensity()) / 255.0);
    double sinkCapacity = -ALPHA * log(pixels[i].getIntensity() / 255.0);

    pixels[i].setSourceCapacity(sourceCapacity);
    pixels[i].setSinkCapacity(sinkCapacity);
}

void Graph::depthFT(const int l,const int c){
    int i = index(l, c);
    if (pixels[i].getState() != 0) return;
    pixels[i].setState(1);

    int lines[4];
    int columns[4];
    int n = near(l, c, lines, columns);

    for (int v = 0; v < n; v++){
        depthFT(lines[v], columns[v]);
    }
}

void Graph::breadthFT(const int startL, const int startC) {
    // Initialize a queue for breadth-first traversal
    std::queue<std::pair<int, int>> q;

    q.push(std::make_pair(startL, startC));

    while (!q.empty()) {
        std::pair<int, int> current = q.front();
        q.pop();

        int l = current.first;
        int c = current.second;
        int i = index(l, c);

        if (pixels[i].getState() != 0) {
            continue;
        }

        pixels[i].setState(1);

        int lines[4];
        int columns[4];
        int n = near(l, c, lines, columns);

        for (int v = 0; v < n; v++) {
            int neighborL = lines[v];
            int neighborC = columns[v];

            if (pixels[index(neighborL, neighborC)].getState() == 0) {
                q.push(std::make_pair(neighborL, neighborC));
            }
        }
    }
}

void Graph::bfsWithAugmentedPath() {
    augmentedPath.clear();
    std::queue<int> queue;
    std::vector<bool> visited(L * C, false);
    std::vector<int> predecessor(L * C, -1);

    visited[S.getState()] = true;
    queue.push(S.getIntensity());

    while (!queue.empty()) {
        // Dequeue a pixel from the queue
        int currentPixel = queue.front();
        queue.pop();

        // Enqueue unvisited neighbors
        int lines[4];
        int columns[4];
        int n = near(line(currentPixel), column(currentPixel), lines, columns);

        for (int v = 0; v < n; ++v) {
            int neighbor = index(lines[v], columns[v]);

            if (!visited[neighbor] && currentPixel, neighbor > 0) {
                visited[neighbor] = true;
                queue.push(neighbor);
                predecessor[neighbor] = currentPixel;
            }
        }
    }

    // Reconstruct the augmented path from sink to source using the predecessor array
    int currentPixel = T.getIntensity();
    while (currentPixel != -1) {
        augmentedPath.push_back(&pixels[currentPixel]);
        currentPixel = predecessor[currentPixel];
    }

    // Reverse the augmented path to have it from source to sink
    std::reverse(augmentedPath.begin(), augmentedPath.end());
}

void Graph::printGraph(const int l,const int c){
    int i = index(l, c);
    if (pixels[i].getState() != 0) return;
    pixels[i].setState(1);

    int lines[4];
    int columns[4];
    int n = near(l, c, lines, columns);

    for (int v = 0; v < n; v++){
        std::cout << pixels[i].getIntensity() << std::endl;
        printGraph(lines[v], columns[v]);
    }
}

void Graph::displayGrid() const{
    return;
}

void Graph::saveToFile(std::string filename) const{
    return;
}
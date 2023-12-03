//Gaspard Gentil

#include "graph.hpp"
#include <queue>

Graph::Graph() : L(0), C(0), pixels(nullptr) {
    pixels = new Pixel[L * C];
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
}


Graph::~Graph() {
    delete[] pixels;
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
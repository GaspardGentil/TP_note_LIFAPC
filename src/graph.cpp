//Gaspard Gentil

#include "graph.hpp"

Graph::Graph(){
    L = 0;
    C = 0;
    tableau = new int[0*0];
    state = new int[0*0];
}

Graph::Graph(const char* filename){
    std::ifstream in(filename);
    if (in.fail()){
        std::cout << "error" << filename << "\n";
        exit(1);
    }

    std::string magic;
    in >> magic;
    if (magic != "P2"){
        in.close();
        exit(1);
    }
    // int lines, columns;
    if (!(in >> L >> C)){
        L = 0;
        C = 0;
        in.close();
        exit(1);
    }
    tableau = new int[L * C];

    for (int i = 0; i < L * C; i++){
        if (!(in >> tableau[i])){
            exit(1);
        }
    }
    in.close();
}

Graph::~Graph() {
    delete[] tableau;
    delete[] state;
}



int Graph::pixel(const int l, const int c){
    return pixel(index(l,c));
}
int Graph::pixel(const int i){
    assert(i >= 0);
    assert(i < L * C);
    return tableau[i];
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

void Graph::parcours(const int l,const int c){
    int i = index(l, c);
    if (state[i] != 0) return;
    state[i] = 1;

    int lines[4];
    int columns[4];
    int n = near(l, c, lines, columns);

    for (int v = 0; v < n; v++){
        parcours(lines[v], columns[v]);
    }
}

void Graph::printGraph(const int l,const int c){
    int i = index(l, c);
    if (state[i] != 0) return;
    state[i] = 1;

    int lines[4];
    int columns[4];
    int n = near(l, c, lines, columns);

    for (int v = 0; v < n; v++){
        std::cout << tableau[i] << std::endl;
        parcours(lines[v], columns[v]);
    }
}
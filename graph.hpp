//Gaspard Gentil

#pragma once

#include "pixel.hpp"
#include <cassert>
#include <iostream>
#include <fstream>

class Graph{
private :
    int L,C;
    int* tableau;
    int* state;

public :

    Graph(const char* filename){
        std::ifstream in(filename);
        if(in.fail()) {std::cout << "error" << filename << "\n"; exit(1); }

        std::string magic;
        in >> magic;
        if(magic != "P2") {in.close(); exit(1);}
        int lines, columns;
        if(!(in >> L >> C)) {L = 0; C = 0; in.close(); exit(1);}
        tableau = new int[lines*columns];

        for(int i=0;i<L*C;i++){
            if(!(in >> tableau[i])) {exit(1);}
        }
        in.close();

    }

    int pixel(const int l,const int c){return pixel(index(l,c));}
    int pixel(const int i){
        assert(i >=0);
        assert(i < L*C);
        return tableau[i];
    }

    int index(const int l, const int c){return l*C +c;}
    int line(const int i){return i / C;}
    int column(const int i){return i % C;}

    bool exists(const int l, const int c){
        if(l < 0) return false;
        if(l>= L) return false;
        if(c < 0) return false;
        if(c >= C) return false;
        return true;
    }

    Graph();

    int near(const int l, const int c, int lines[4],int columns[4]){
        int n = 0;
        if(exists(l+1,c)){ //voisin du haut
            lines[n] = l+1; columns[n] = c;
            n++;
        }

        if(exists(l-1,c)){ //voisin du bas
            lines[n] = l-1; columns[n] = c;
            n++;
        }

        if(exists(l,c-1)){ //voisin de gauche
            lines[n] = l; columns[n] = c+1;
            n++;
        }

        if(exists(l,c+1)){ //voisin de droite
            lines[n] = l; columns[n] = c+1;
            n++;
        }
        return n;

    }

    void parcours(const int l,const int c){
        int i = index(l,c);
        if(state[i] != 0)
            return;
        state[i] = 1;

        int lines[4];
        int columns[4];
        int n = near(l,c,lines,columns);

        for(int v=0;v<n;v++){
            parcours(lines[v],columns[v]);
        }
    }

    void printGraph(const int l,const int c){
        int i = index(l,c);
        if(state[i] != 0)
            return;
        state[i] = 1;

        int lines[4];
        int columns[4];
        int n = near(l,c,lines,columns);

        for(int v=0;v<n;v++){
            std::cout << tableau[i] << std::endl;
            parcours(lines[v],columns[v]);
        }
    }

};
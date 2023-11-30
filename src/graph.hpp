//Gaspard Gentil

#pragma once

#include <cassert>
#include <iostream>
#include <fstream>

class Graph{
private :
    int L,C;
    int S,P;
    int* pixelValues;
    int* pixelFlow;
    int* pixelCapacity;
    int* state;

public :

    Graph();

    Graph(std::string filename);

    ~Graph();

    int getL() const { return L; }
    int getC() const { return C; }

    /******************************/

    int pixel(const int l,const int c);
    int pixel(const int i);

    int index(const int l, const int c);
    int line(const int i);
    int column(const int i);

    bool exists(const int l, const int c);

    int near(const int l, const int c, int lines[4],int columns[4]);

    void depthFT(const int l,const int c);

    void printGraph(const int l,const int c);
    
    void displayGrid() const;
    void saveToFile(std::string filename) const;
};
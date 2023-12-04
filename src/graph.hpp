//Gaspard Gentil

#pragma once

#include <cassert>
#include <iostream>
#include <fstream>
#include "pixel.hpp"

class Graph{
private :
    int L,C; //dimension of the image
    Pixel* pixels; //array of pixels (representing the image)

public :

    Graph(); //default constructor

    Graph(std::string filename); //constructor by file

    ~Graph(); //destructor

    //accessors
    int getL() const { return L; }
    int getC() const { return C; }

    /******************************/

    //ways to get the intensity of a pixel
    int pixel(const int l,const int c);
    int pixel(const int i);

    int index(const int l, const int c); //getting the index of the pixel in the graph
    int line(const int i); //special accessors for the dimensions
    int column(const int i);

    bool exists(const int l, const int c); //test if the pixel exist

    //put the neighbors in the arrays
    int near(const int l, const int c, int lines[4],int columns[4]); 

    //Traversal algorithms
    void depthFT(const int l,const int c);
    void breadthFT(const int l, const int c);

    void printGraph(const int l,const int c); //print the intensity in the array
    
    //ways to display the image and saving the file (additional functions)
    void displayGrid() const;
    void saveToFile(std::string filename) const;
};
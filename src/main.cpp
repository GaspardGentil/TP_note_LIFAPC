//Gaspard Gentil

#include <iostream>
#include "graph.hpp"

int main(int argc, char const *argv[])
{
    const char*file = "img/baboon.ascii.pgm";
    Graph test(file);
    test.printGraph(0,0);
    test.parcours(2,2);
    return 0;
}

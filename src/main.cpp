//Gaspard Gentil

#include <iostream>
#include "graph.hpp"

int main(int argc, char const *argv[])
{
    
    std::string file = "./img/baboon.reduced.pgm";
    Graph test(file);
    test.printGraph(0,0);
    test.breadthFT(2,2);
    std::cout << "main finished" << std::endl;
    return 0;
}

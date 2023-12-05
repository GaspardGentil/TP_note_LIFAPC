//Gaspard Gentil

#include <iostream>
#include "graph.hpp"

int main(int argc, char const *argv[])
{
    std::string file = "./img/baboon.reduced.pgm";
    Graph test(file);


    test.breadthFT(2,2);
    bool res;
    res = test.findAugmentedPath();
    std::cout << res;

    std::cout << "main finished" << std::endl;
    return 0;
}

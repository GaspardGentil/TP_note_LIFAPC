//Gaspard Gentil

#include <iostream>
#include "graph.hpp"

int main(int argc, char const *argv[])
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <image_filename>" << std::endl;
        return 1;
    }
    //opening the image file
    std::string imageFilename(argv[1]);
    std::string filename = "./img/" + imageFilename;

    //operations on the image (such as finding the augmented path, traversal etc.)
    Graph graph(filename);

    graph.initializeGraph();
    //graph.bfsWithAugmentedPath();
    graph.depthFT(1,1);
    graph.getAugmentedPath();

    //saving aand closing (not implemented yet)
    graph.displayGrid();
    graph.saveToFile("./img/new_graph.pgm");

    std::cout << "main finished" << std::endl;
    return 0;
}

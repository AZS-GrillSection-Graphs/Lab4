#include <iostream>
#include "DiGraph.h"


using Component = std::vector<int>;


int main(int argc, const char * argv[])
{
    srand(static_cast<unsigned int>(time(nullptr)));

    /////////////// Task 1 ///////////////
    DiGraph graph(5, 0.4);
    graph.PrintAllRepresentations();


    /////////////// Task 2 ///////////////
    Component biggestComp = graph.Kosaraju();
    std::cout << "Biggest Component" << std::endl;
    DiGraph::PrintComponent(biggestComp);

    return 0;
}
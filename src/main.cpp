#include <iostream>

#include "DiGraph.h"
#include "StronglyConnectedDiGraph.h"


int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    std::cout << "/////////////// Task 1 ///////////////" << std::endl << std::endl;
    DiGraph graph(4, 0.7);
    graph.PrintAllRepresentations();
    graph.Draw();


    std::cout << "/////////////// Task 2 ///////////////" << std::endl << std::endl;
    Component biggestComponent = graph.Kosaraju();
    std::cout << "Component from Kosaraju algorithm: " << std::endl;
    biggestComponent.PrintOriginIndex();

    StronglyConnectedDiGraph SCDiGraph =
            StronglyConnectedDiGraph::FindStronglyConnectedDiGraph(graph, biggestComponent);

    std::cout << std::endl << "Strongly Connected DiGraph: " << std::endl;
    SCDiGraph.Print();


    std::cout << "/////////////// Task 3 ///////////////" << std::endl << std::endl;
    SCDiGraph.AssignWeights(-5, 10);
    SCDiGraph.Draw();


    std::cout << "/////////////// Task 4 ///////////////" << std::endl << std::endl;
    SCDiGraph.Johnson();


    return 0;
}
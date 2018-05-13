#include <iostream>

#include "DiGraph.h"
#include "StronglyConnectedDiGraph.h"


int main(int argc, const char * argv[])
{
    srand(static_cast<unsigned int>(time(nullptr)));

    std::cout << "/////////////// Task 1 ///////////////" << std::endl << std::endl;
    DiGraph graph(5, 0.5);
    graph.PrintAllRepresentations();
    graph.Draw();


    std::cout << "/////////////// Task 2 ///////////////" << std::endl;
    Component comp = graph.Kosaraju();

    std::cout << "Component from Kosaraju algorithm: " << std::endl;
    comp.Print();

    StronglyConnectedDiGraph SCDiGraph = StronglyConnectedDiGraph::FindStronglyConnectedDiGraph(graph, comp);

    std::cout << std::endl << "Strongly Connected DiGraph: " << std::endl;
    SCDiGraph.Print();


    std::cout << "/////////////// Task 3 ///////////////" << std::endl << std::endl;
    SCDiGraph.AssignWeights(-5, 10);
    SCDiGraph.BellmanFord(0);
    SCDiGraph.Draw();


    std::cout << "/////////////// Task 4 ///////////////" << std::endl << std::endl;
    


    return 0;
}
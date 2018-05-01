#include <iostream>
#include "DiGraph.h"



int main(int argc, const char * argv[])
{
    srand(static_cast<unsigned int>(time(nullptr)));

    /////////////// Task 1 ///////////////
    DiGraph graph(5, 0.3);
    graph.PrintAllRepresentations();


    /////////////// Task 2 ///////////////


    return 0;
}
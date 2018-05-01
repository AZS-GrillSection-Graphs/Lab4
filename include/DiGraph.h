//
// Created by piotr on 01.05.18.
//

#ifndef GRAPHS4_DIGRAPH_H
#define GRAPHS4_DIGRAPH_H


#include "AdjList.h"


class DiGraph
{
public:
    DiGraph(const int numberOfVertices, const double probability);
    ~DiGraph();

    void PrintAllRepresentations() const;

    void Kosaraju();

private:
    AdjMatrix * m_graphRepr;
};

#endif //GRAPHS4_DIGRAPH_H

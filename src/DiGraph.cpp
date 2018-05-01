//
// Created by piotr on 01.05.18.
//
#include <AdjMatrix.h>
#include <GraphException.h>
#include <iostream>
#include "DiGraph.h"

DiGraph::DiGraph(const int numberOfVertices, const double probability)
{
    try
    {
        if(numberOfVertices < 0)
            throw(GraphException("Graph cannot has negative amount of vertices."));
        if(probability < 0 || probability > 1)
            throw(GraphException("Invalid value of probability."));
    }
    catch(GraphException & er)
    {
        std::cerr << er.what() << std::endl;
        exit(EXIT_FAILURE);
    }
    m_graphRepr = new AdjMatrix(numberOfVertices, probability);
    m_graphRepr->Print();
}

DiGraph::~DiGraph()
{
    delete m_graphRepr;
}

void DiGraph::PrintAllRepresentations() const
{
    m_graphRepr->ShowAllRepresentations();
}

void DiGraph::Kosaraju()
{
    AdjList adjList = m_graphRepr->ConvertToAdjList();
}

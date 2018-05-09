//
// Created by piotr on 01.05.18.
//
#include <iostream>
#include <map>

#include "AdjMatrix.h"
#include "GraphException.h"
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

void DFS_Visit(const unsigned index, AdjList & adjList, std::vector<bool> & visited, std::vector<int> & stack)
{
    visited[index] = true;

    for(unsigned i = 0; i < adjList[index].size(); ++i)
    {
        if(visited[adjList[index][i]] == false)
        {
            DFS_Visit(adjList[index][i], adjList, visited, stack);
        }
    }
    stack.emplace_back(index);
}

AdjList TransposeGraph(AdjList & adjList)
{
    std::vector<std::vector<int>> transAdjList(adjList.NumOfVertices());

    for(unsigned i = 0; i < adjList.NumOfVertices(); ++i)
    {
        for(int element : adjList[i])
        {
            transAdjList[element].emplace_back(i);
        }
    }

    return AdjList(transAdjList);
}

void Components_R(int numberOfComponent, int v, AdjList & adjList, std::vector<int> & component)
{
    for(unsigned u = 0; u < adjList[v].size(); ++u)
    {
        if(component[adjList[v][u]] == -1)
        {
            component[adjList[v][u]] = numberOfComponent;
            Components_R(numberOfComponent, adjList[v][u], adjList, component);
        }
    }
}

std::vector<int> FindBiggestComponent(std::vector<int> comp)
{
    int max = 0;
    int most_common = -1;

    std::map<int, int> m;

    for(auto vi = comp.begin(); vi != comp.end(); vi++)
    {
        m[*vi]++;

        if (m[*vi] > max)
        {
            max = m[*vi];
            most_common = *vi;
        }
    }

    std::vector<int> biggest;

    for(unsigned i = 0; i < comp.size(); ++i)
    {
        if(comp[i] == most_common)
            biggest.emplace_back(i);
    }

    return biggest;
}

std::vector<int> DiGraph::Kosaraju()
{
    AdjList adjList = m_graphRepr->ConvertToAdjList();

    unsigned numberOfVertices = adjList.NumOfVertices();

    std::vector<bool> visited;
    std::vector<int> stack;

    for(unsigned i = 0; i < numberOfVertices; ++i)
    {
        visited.emplace_back(false);
    }

    for(unsigned i = 0; i < numberOfVertices; ++i)
    {
        if(visited[i] == false)
            DFS_Visit(i, adjList, visited, stack);
    }

    AdjList transAdjList = TransposeGraph(adjList);

    int numberOfComponent = 0;
    std::vector<int> component;

    for(int i = 0; i < numberOfVertices; ++i)
    {
        component.emplace_back(-1);
    }

    while(!stack.empty())
    {
        int v = stack.back();
        stack.pop_back();

        if(component[v] == -1)
        {
            ++numberOfComponent;
            component[v] = numberOfComponent;
            Components_R(numberOfComponent, v, transAdjList, component);
        }
    }

    std::vector<int> biggestComponent = FindBiggestComponent(component);

    return biggestComponent;
}

void DiGraph::PrintComponent(std::vector<int> comp)
{
    for(auto & item : comp)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

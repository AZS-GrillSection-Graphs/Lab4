//
// Created by piotr on 09.05.18.
//

#ifndef GRAPHS4_STRONGLYCONNECTEDDIGRAPH_H
#define GRAPHS4_STRONGLYCONNECTEDDIGRAPH_H


#include "AdjList.h"

class DiGraph;



class StronglyConnectedDiGraph
{
public:
    static StronglyConnectedDiGraph FindStronglyConnectedDiGraph(const DiGraph &graph, const Component &component);

    explicit StronglyConnectedDiGraph(const std::vector<std::vector<int>> adjList);
    ~StronglyConnectedDiGraph();
    void Print() const;
    void Draw() const;


private:
    AdjList * m_adjList;
};

#endif //GRAPHS4_STRONGLYCONNECTEDDIGRAPH_H

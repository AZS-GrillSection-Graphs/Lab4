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


    void AssignWeights(const int min, const int max);
    bool BellmanFord(const int s);


private:
    static int iRand(const int min, const int max);
    void Init(std::vector<int> & d, std::vector<int> & p, const int s);


    AdjList * m_adjList;
    std::vector<std::vector<int>> m_weights;
};

#endif //GRAPHS4_STRONGLYCONNECTEDDIGRAPH_H

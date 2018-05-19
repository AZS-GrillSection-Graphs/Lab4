#ifndef GRAPHS4_STRONGLYCONNECTEDDIGRAPH_H
#define GRAPHS4_STRONGLYCONNECTEDDIGRAPH_H


#include "AdjList.h"


class DiGraph;


class StronglyConnectedDiGraph
{
public:
    static StronglyConnectedDiGraph FindStronglyConnectedDiGraph(const DiGraph &graph,
                                                                 const Component &component);
    explicit StronglyConnectedDiGraph(const std::vector<std::vector<int>> adjList);
    ~StronglyConnectedDiGraph();
    void Print() const;
    void Draw() const;
    void AssignWeights(const int min, const int max);
    static bool BellmanFord(std::vector<std::vector<int>> & adjList,
                     std::vector<std::vector<int>> & weights,
                     std::vector<int> & d, const int s);
    std::vector<std::vector<int>> Johnson();

private:
    static int iRand(const int min, const int max);
    static void Init(const int size, std::vector<int> & d, std::vector<int> & p, const int s);
    void PrintWeightsToFile(const char * fileName) const;
    void Add_S(std::vector<std::vector<int>> & adjList,
               std::vector<std::vector<int>> & weights);
    std::vector<int> Dijkstra(const int u);
    int IndexOfElement(const std::vector<bool> & vec, const bool element) const;
    static void PrintMatrix(const std::vector<std::vector<int>> & matrix);
    void PrintPaths(const int chosenVertex,
                    std::vector<int> &predecessorsArray) const;

    AdjList * m_adjList;
    std::vector<std::vector<int>> m_weights;
};

#endif //GRAPHS4_STRONGLYCONNECTEDDIGRAPH_H

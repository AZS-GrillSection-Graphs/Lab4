#ifndef GRAPHS4_ADJLIST_H
#define GRAPHS4_ADJLIST_H


#include "AdjMatrix.h"
#include "IncMatrix.h"
#include "Component.h"


class AdjList
{
public:
    AdjList() {}
    explicit AdjList(const std::vector<std::vector<int>> adjList);
    static AdjList ConstructAdjListFromAdjMatrix(std::vector<std::vector<int>> adjMatrix);
    static AdjList ConstructAdjListFromComponent(const AdjList & adjList, const Component & component);

    IncMatrix ConvertToIncMatrix() const;

    void Print() const;

    unsigned NumOfVertices() const;
    std::vector<int> & operator[](const int index);
    std::vector<int> operator[](const int index) const;
    std::vector<std::vector<int>> GetAdjList() const;

    void RemoveEdgesInVertical(const int vertical, const int verticalToDelete);

private:
    std::vector<std::vector<int>>m_adjList;
};

#endif //GRAPHS4_ADJLIST_H

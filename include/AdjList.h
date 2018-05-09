//
// Created by piotr on 01.05.18.
//

#ifndef GRAPHS4_ADJLIST_H
#define GRAPHS4_ADJLIST_H


#include "AdjMatrix.h"


class AdjList
{
public:
    AdjList();
    explicit AdjList(const std::vector<std::vector<int>> adjList);
    static AdjList ConstructAdjListFromAdjMatrix(std::vector<std::vector<int>> adjMatrix);

    unsigned NumOfVertices() const {return static_cast<unsigned int>(m_adjList.size());}
    std::vector<int> & operator[](const int index) {return m_adjList[index];}

    virtual void Print() const;


private:
    std::vector<std::vector<int>>m_adjList;

};

#endif //GRAPHS4_ADJLIST_H

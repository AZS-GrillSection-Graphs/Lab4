//
// Created by piotr on 01.05.18.
//

#ifndef GRAPHS4_ADJLIST_H
#define GRAPHS4_ADJLIST_H


#include "AdjMatrix.h"


class AdjList
{
public:
    AdjList(const std::vector<std::vector<int>> & adjMatrix);

    virtual void Print() const;


private:
    std::vector<std::vector<int>>m_adjList;

};

#endif //GRAPHS4_ADJLIST_H

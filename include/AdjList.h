//
// Created by piotr on 01.05.18.
//

#ifndef GRAPHS4_ADJLIST_H
#define GRAPHS4_ADJLIST_H


#include "GraphRepresentation.h"
#include "AdjMatrix.h"


class AdjList : public GraphRepresentation
{
public:
    AdjList(const std::vector<std::vector<int>> & adjMatrix);

    virtual void Print() const override;
    virtual const AdjList * Convert(std::string ReprName) const override;

    virtual void ShowAllRepresentations() const override;

private:
    std::vector<std::vector<int>>m_adjList;

};

#endif //GRAPHS4_ADJLIST_H

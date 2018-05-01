//
// Created by piotr on 01.05.18.
//

#ifndef GRAPHS4_ADJMATRIX_H
#define GRAPHS4_ADJMATRIX_H

#include <vector>
#include "GraphRepresentation.h"


class AdjList;
class IncMatrix;


class AdjMatrix : public GraphRepresentation
{
public:
    AdjMatrix(const int numberOfVertices, const double probability);
    virtual void Print() const override;
    virtual const GraphRepresentation * Convert(std::string ReprName) const override;
    AdjList * ConvertToAdjList() const;
    IncMatrix * ConvertToIncMatrix() const;
    virtual void ShowAllRepresentations() const override;

private:
    std::vector<std::vector<int>>m_adjMatrix;
};

#endif //GRAPHS4_ADJMATRIX_H

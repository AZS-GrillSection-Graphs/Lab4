//
// Created by piotr on 01.05.18.
//

#ifndef GRAPHS4_ADJMATRIX_H
#define GRAPHS4_ADJMATRIX_H

#include <vector>
#include "GraphRepresentation.h"


class AdjMatrix : public GraphRepresentation
{
public:
    AdjMatrix(const int numberOfVertices, const double probability);
    void Print() const;

private:
    std::vector<std::vector<int>>m_adjMatrix;
};

#endif //GRAPHS4_ADJMATRIX_H

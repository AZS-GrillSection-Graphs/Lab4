//
// Created by piotr on 01.05.18.
//

#ifndef GRAPHS4_INCMATRIX_H
#define GRAPHS4_INCMATRIX_H


#include "GraphRepresentation.h"
#include "AdjMatrix.h"


class IncMatrix : public GraphRepresentation
{
public:
    IncMatrix(const std::vector<std::vector<int>> & adjMatrix);

    virtual void Print() const override;
    virtual const IncMatrix * Convert(std::string ReprName) const override;

    virtual void ShowAllRepresentations() const override;

private:
    std::vector<std::vector<int>>m_incMatrix;
};

#endif //GRAPHS4_INCMATRIX_H

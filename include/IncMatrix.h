//
// Created by piotr on 01.05.18.
//

#ifndef GRAPHS4_INCMATRIX_H
#define GRAPHS4_INCMATRIX_H


#include "AdjMatrix.h"


class IncMatrix
{
public:
    IncMatrix(const std::vector<std::vector<int>> & adjMatrix);

    virtual void Print() const;
    void PrintToFile() const;


private:
    std::vector<std::vector<int>>m_incMatrix;
};

#endif //GRAPHS4_INCMATRIX_H

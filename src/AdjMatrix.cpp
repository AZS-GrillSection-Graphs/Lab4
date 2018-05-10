//
// Created by piotr on 01.05.18.
//
#include <iostream>
#include <iomanip>

#include "AdjList.h"


int iRand(const int min, const int max)
{
    return rand() % max + min;
}

AdjMatrix::AdjMatrix(const int numberOfVertices, const double probability)
{


    for(int i = 0; i < numberOfVertices; ++i)
    {
        std::vector<int>row;

        for(int j = 0; j < numberOfVertices; ++j)
        {
            row.emplace_back(0);
        }

        m_adjMatrix.emplace_back(row);
    }

    for(int i = 0; i < numberOfVertices; ++i)
    {
        for(int j = 0; j < numberOfVertices; ++j)
        {
            int random = iRand(1, 100);
            int prob = static_cast<int>(probability * 100);

            if(i != j && prob >= random)
            {
                m_adjMatrix[i][j] = 1;
            }
        }
    }

}

void AdjMatrix::Print() const
{
    std::cout << "Macierz Sasiedztwa" << std::endl;

    for(auto & row : m_adjMatrix)
    {
        for(auto & item : row)
        {
            std::cout << std::setw(2) << item << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

AdjList AdjMatrix::ConvertToAdjList() const
{
    return AdjList::ConstructAdjListFromAdjMatrix(m_adjMatrix);
}

IncMatrix AdjMatrix::ConvertToIncMatrix() const
{
    return IncMatrix::ConstructIncMatrixFromAdjMatrix(m_adjMatrix);
}

void AdjMatrix::ShowAllRepresentations() const
{
    IncMatrix incMatrix = ConvertToIncMatrix();
    AdjList adjList = ConvertToAdjList();

    this->Print();
    incMatrix.Print();
    adjList.Print();
}








//
// Created by piotr on 01.05.18.
//
#include <iostream>
#include <GraphException.h>
#include <iomanip>
#include "AdjList.h"
#include "IncMatrix.h"
#include "AdjMatrix.h"


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
            int random = GraphRepresentation::iRand(1, 100);
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

const GraphRepresentation * AdjMatrix::Convert(std::string ReprName) const
{
    if(ReprName == "Macierz Sasiedztwa")
    {
        return this;
    }
    else if (ReprName == "Lista Sasiedztwa")
    {
        return this->ConvertToAdjList();
    }
    else if (ReprName == "Macierz Incydencji")
    {
        return this->ConvertToIncMatrix();
    }
    else
        throw GraphException("Name of graph representation is invalid.");
}

AdjList * AdjMatrix::ConvertToAdjList() const
{
    return new AdjList(m_adjMatrix);
}

IncMatrix *AdjMatrix::ConvertToIncMatrix() const
{
    return new IncMatrix(m_adjMatrix);
}

void AdjMatrix::ShowAllRepresentations() const
{
    const GraphRepresentation * incMatrix = Convert("Macierz Incydencji");
    const GraphRepresentation * adjList = Convert("Lista Sasiedztwa");

    this->Print();
    incMatrix->Print();
    adjList->Print();

    delete incMatrix;
    delete adjList;
}








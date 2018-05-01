//
// Created by piotr on 01.05.18.
//

#include <vector>
#include <IncMatrix.h>
#include <iostream>
#include <iomanip>


IncMatrix::IncMatrix(const std::vector <std::vector<int>> & adjMatrix)
{
    int numberOfEdges = 0;

    for(int i = 0; i < adjMatrix.size(); ++i)
    {
        for(int j = 0; j < adjMatrix[i].size(); ++j)
        {
            if(adjMatrix[i][j] == 1)
                ++numberOfEdges;
        }
    }


    for(int i = 0; i < adjMatrix.size(); ++i)
    {
        std::vector<int> row;

        for(int j = 0; j < numberOfEdges; ++j)
        {
            row.emplace_back(0);
        }

        m_incMatrix.emplace_back(row);
    }


    int edge = 0;

    for(int i = 0; i < adjMatrix.size(); ++i)
    {
        for(int j = 0; j < adjMatrix[i].size(); ++j)
        {
            if(adjMatrix[i][j] == 1)
            {
                m_incMatrix[i][edge] = -1;
                m_incMatrix[j][edge] = 1;
                ++edge;
            }
        }
    }
}

void IncMatrix::Print() const
{
    std::cout << "Macierz Incydencji" << std::endl;

    for(auto & row : m_incMatrix)
    {
        for(auto & item : row)
        {
            std::cout << std::setw(3) << item << " ";
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;
}

const IncMatrix * IncMatrix::Convert(std::string ReprName) const
{
    // TO DO implement
    return nullptr;
}

void IncMatrix::ShowAllRepresentations() const
{
    // TO DO implement
}

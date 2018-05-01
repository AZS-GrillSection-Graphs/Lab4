//
// Created by piotr on 01.05.18.
//

#include <AdjMatrix.h>
#include <AdjList.h>
#include <iostream>
#include <iomanip>


AdjList::AdjList(const std::vector<std::vector<int>> & adjMatrix)
{
    for(unsigned int i = 0; i < adjMatrix.size(); ++i)
    {
        std::vector<int> row;

        for(unsigned int j = 0; j < adjMatrix[i].size(); ++j)
        {
            if(adjMatrix[i][j] == 1)
            {
                row.emplace_back(j + 1);
            }
        }
        m_adjList.emplace_back(row);
    }
}

void AdjList::Print() const
{
    std::cout << "Lista Sasiedztwa" << std::endl;

    for(auto & row : m_adjList)
    {
        for(auto & item : row)
        {
            std::cout << std::setw(2) << item << " ";
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;
}

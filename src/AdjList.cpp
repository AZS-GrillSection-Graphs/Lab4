//
// Created by piotr on 01.05.18.
//

#include <AdjMatrix.h>
#include <AdjList.h>
#include <iostream>
#include <iomanip>




AdjList::AdjList()
{

}

AdjList::AdjList(const std::vector<std::vector<int>> adjList)
{
    m_adjList = adjList;
}

AdjList AdjList::ConstructAdjListFromAdjMatrix(std::vector<std::vector<int>> adjMatrix)
{
    AdjList adjList;
    adjList.m_adjList.clear();

    for(unsigned int i = 0; i < adjMatrix.size(); ++i)
    {
        std::vector<int> row;

        for(unsigned int j = 0; j < adjMatrix[i].size(); ++j)
        {
            if(adjMatrix[i][j] == 1)
            {
                row.emplace_back(j);
            }
        }
        adjList.m_adjList.emplace_back(row);
    }

    return adjList;
}

void AdjList::Print() const
{
    std::cout << "Lista Sasiedztwa" << std::endl;


    for(int i = 0; i < m_adjList.size(); ++i)
    {
        std::cout << i + 1 << ": ";
        for(int j = 0; j < m_adjList[i].size(); ++j)
        {
            std::cout << m_adjList[i][j] + 1 << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

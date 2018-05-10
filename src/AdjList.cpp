//
// Created by piotr on 01.05.18.
//

#include "AdjMatrix.h"
#include "AdjList.h"
#include <iostream>
#include <iomanip>


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

unsigned AdjList::NumOfVertices() const
{
    return static_cast<unsigned int>(m_adjList.size());
}

std::vector<int> &AdjList::operator[](const int index)
{
    return m_adjList[index];
}

std::vector<int> AdjList::operator[](const int index) const
{
    return m_adjList[index];
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

std::vector<std::vector<int>> AdjList::GetAdjList() const
{
    return m_adjList;
}

void AdjList::RemoveEdgesInVertical(const int vertical, const int verticalToDelete)
{
    std::vector<int> newVertical;

    for(int i = 0; i < m_adjList[vertical].size(); ++i)
    {
        if(m_adjList[vertical][i] != verticalToDelete)
            newVertical.emplace_back(m_adjList[vertical][i]);
    }

    m_adjList[vertical].swap(newVertical);
}

AdjList AdjList::ConstructAdjListFromComponent(const AdjList & adjList, const Component & component)
{
    std::vector<std::vector<int>> newAdjList;

    for(int i = 0; i < component.size(); ++i)
    {
        newAdjList.emplace_back(adjList[component[i]]);
    }

    return AdjList(newAdjList);
}

IncMatrix AdjList::ConvertToIncMatrix() const
{
    return IncMatrix::ConstructIncMatrixFromAdjList(m_adjList);
}

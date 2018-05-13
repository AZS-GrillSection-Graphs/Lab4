//
// Created by piotr on 09.05.18.
//

#include <iostream>
#include <climits>
#include "StronglyConnectedDiGraph.h"
#include "DiGraph.h"
#include "IncMatrix.h"


StronglyConnectedDiGraph StronglyConnectedDiGraph::FindStronglyConnectedDiGraph(const DiGraph &graph,
                                                                                const Component &component)
{
    Component biggestComponent = component.FindBiggestComponent();
    AdjList newAdjList = AdjList::ConstructAdjListFromComponent(graph.GetAdjList(), biggestComponent);

    biggestComponent.sort();

    for(unsigned i = 0; i < newAdjList.NumOfVertices(); ++i)
    {
        int j = 0;

        while(j < newAdjList[i].size())
        {
            if(! biggestComponent.IsElementInComponent(newAdjList[i][j]))
            {
                newAdjList.RemoveEdgesInVertical(i, newAdjList[i][j]);
            }
            else
            {
                newAdjList[i][j] = biggestComponent.IndexOfElement(newAdjList[i][j]);
                ++j;
            }
        }
    }

    return StronglyConnectedDiGraph(newAdjList.GetAdjList());
}

StronglyConnectedDiGraph::StronglyConnectedDiGraph(const std::vector<std::vector<int>> adjList)
{
    m_adjList = new AdjList(adjList);
}

StronglyConnectedDiGraph::~StronglyConnectedDiGraph()
{
    delete m_adjList;
}

void StronglyConnectedDiGraph::Print() const
{
    m_adjList->Print();
}

void StronglyConnectedDiGraph::Draw() const
{
    IncMatrix incMatrix = m_adjList->ConvertToIncMatrix();
    incMatrix.PrintToFile();

    std::string command = "python3 DiGraphVisualization.py MacierzIncydencji.txt";
    system(command.c_str());
}

void StronglyConnectedDiGraph::AssignWeights(const int min, const int max)
{
    m_weights = std::vector<std::vector<int>>(m_adjList->NumOfVertices());

    for(int i = 0; i < m_adjList->NumOfVertices(); ++i)
    {
        for(int j = 0; j < m_adjList->GetAdjList()[i].size(); ++j)
        {
            m_weights[i].emplace_back(StronglyConnectedDiGraph::iRand(min, max));
        }
    }

    for(int i = 0; i < m_adjList->NumOfVertices(); ++i)
    {
        for(int j = 0; j < m_adjList->GetAdjList()[i].size(); ++j)
        {
            std::cout << "Waga[" << i << "][" << j << "] = " << m_weights[i][j] << std::endl;
        }
    }
}

int StronglyConnectedDiGraph::iRand(const int min, const int max)
{
    return rand() % (max - min + 1) + min;
}

bool StronglyConnectedDiGraph::BellmanFord(const int s)
{
    std::vector<int> d;
    std::vector<int> p;

    const int n = m_adjList->NumOfVertices();

    Init(d, p, s);

    for(int i = 0; i < n - 1; ++i)
    {
        for(int x = 0; x < n; ++x)
        {
            for(int y = 0; y < m_adjList->GetAdjList()[x].size(); ++y)
            {
                if(d[m_adjList->GetAdjList()[x][y]] > d[x] + m_weights[x][y])
                {
                    d[m_adjList->GetAdjList()[x][y]] = d[x] + m_weights[x][y];
                    p[m_adjList->GetAdjList()[x][y]] = x;
                }
            }
        }
    }

    for(int x = 0; x < n - 1; ++x)
    {
        for (int y = 0; y < m_adjList->GetAdjList()[x].size(); ++y)
        {
            if(d[m_adjList->GetAdjList()[x][y]] > d[x] + m_weights[x][y])
                return false;
        }
    }

    return true;
}

void StronglyConnectedDiGraph::Init(std::vector<int> &d, std::vector<int> &p, const int s)
{
    for(int i = 0; i < m_adjList->NumOfVertices(); ++i)
    {
        d.emplace_back(INT_MAX);
        p.emplace_back(-1);
    }

    d[s] = 0;
}

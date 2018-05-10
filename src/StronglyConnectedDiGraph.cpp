//
// Created by piotr on 09.05.18.
//

#include <iostream>
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

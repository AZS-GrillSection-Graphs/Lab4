#include <iostream>
#include <climits>
#include <fstream>
#include <iomanip>
#include "StronglyConnectedDiGraph.h"
#include "DiGraph.h"
#include "IncMatrix.h"


StronglyConnectedDiGraph StronglyConnectedDiGraph::FindStronglyConnectedDiGraph
        (const DiGraph &graph, const Component &component)
{
    Component biggestComponent = component.FindBiggestComponent();
    AdjList newAdjList = AdjList::ConstructAdjListFromComponent(graph.GetAdjList(),
            biggestComponent);

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

    std::string command = "python3 DiGraphVisualizationWeights.py MacierzIncydencji.txt Wagi.txt";
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
            std::cout << "Weight[" << i << "][" << j << "] = " << m_weights[i][j] << std::endl;
        }
        std::cout << std::endl;
    }

    PrintWeightsToFile("Wagi.txt");
}

void StronglyConnectedDiGraph::PrintWeightsToFile(const char * fileName) const
{
    std::ofstream weightsFile;

    if (!weightsFile.is_open())
    {
        weightsFile.open(fileName, std::ios::out);

        if(!weightsFile)
        {
            std::cerr << "Failed to open " << fileName << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    for(auto & row : m_weights)
    {
        for(auto & item : row)
        {
            weightsFile << item << std::endl;
        }
    }

    weightsFile.close();
}

int StronglyConnectedDiGraph::iRand(const int min, const int max)
{
    return rand() % (max - min + 1) + min;
}

bool StronglyConnectedDiGraph::BellmanFord(std::vector<std::vector<int>> & adjList,
                                           std::vector<std::vector<int>> & weights,
                                           std::vector<int> & d, const int s)
{
    std::vector<int> p;
    const int n = adjList.size();
    StronglyConnectedDiGraph::Init(n, d, p, s);

    for(int i = 0; i < n - 1; ++i)
    {
        for(int x = 0; x < n; ++x)
        {
            for(int y = 0; y < adjList[x].size(); ++y)
            {
                if(d[adjList[x][y]] > d[x] + weights[x][y])
                {
                    d[adjList[x][y]] = d[x] + weights[x][y];
                    p[adjList[x][y]] = x;
                }
            }
        }
    }

    for(int x = 0; x < n; ++x)
    {
        for (int y = 0; y < adjList[x].size(); ++y)
        {
            if(d[adjList[x][y]] > d[x] + weights[x][y])
                return false;
        }
    }

    return true;
}

void StronglyConnectedDiGraph::Init(const int size, std::vector<int> &d, std::vector<int> &p,
                                    const int s)
{
    for(int i = 0; i < size; ++i)
    {
        d.emplace_back(1000);
        p.emplace_back(-1);
    }

    d[s] = 0;
}

std::vector<std::vector<int>> StronglyConnectedDiGraph::Johnson()
{
    std::vector<std::vector<int>> newAdjList;
    std::vector<std::vector<int>> newWeights;

    Add_S(newAdjList, newWeights);

    const int sizeOfNewGraph = newAdjList.size();
    std::vector<int> h;
    bool notNegativeCycle = BellmanFord(newAdjList, newWeights, h, sizeOfNewGraph - 1);

    if(! notNegativeCycle)
    {
        std::cerr <<
                  "Graph contains a negative-weight cycle. Please, try to draw the graph again."
                  << std::endl;
        exit(0);
    }

    for(int u = 0; u < sizeOfNewGraph - 1; ++u)
    {
        for(int v = 0; v < newAdjList[u].size(); ++v)
        {
            m_weights[u][v] += h[u] - h[(*m_adjList)[u][v]];
        }
    }

    const int sizeOfOldGraph = m_adjList->NumOfVertices();

    std::vector<std::vector<int>> dMatrix(sizeOfOldGraph, std::vector<int>(sizeOfOldGraph));

    for(int u = 0; u < sizeOfOldGraph; ++u)
    {
        std::vector<int> d = Dijkstra(u);

        for(int v = 0; v < sizeOfOldGraph; ++v)
        {
            dMatrix[u][v] = d[v] - h[u] + h[v];
        }
    }

    StronglyConnectedDiGraph::PrintMatrix(dMatrix);

    return dMatrix;
}

void StronglyConnectedDiGraph::Add_S(std::vector<std::vector<int>> & adjList,
                                     std::vector<std::vector<int>> & weights)
{
    adjList = m_adjList->GetAdjList();
    weights = m_weights;

    int sizeOfGraph = adjList.size();
    std::vector<int> newVertex;
    std::vector<int> newVertexWeights;
    for(int i = 0; i < sizeOfGraph; ++i)
    {
        newVertex.emplace_back(i);
        newVertexWeights.emplace_back(0);
    }

    adjList.emplace_back(newVertex);
    weights.emplace_back(newVertexWeights);
}

std::vector<int> StronglyConnectedDiGraph::Dijkstra(const int u)
{
    std::vector<int> d;
    std::vector<int> p;
    const int sizeOfGraph = m_adjList->NumOfVertices();


    Init(sizeOfGraph, d, p, u);

    std::vector<bool> S(sizeOfGraph, false);

    for(int i = 0; i < sizeOfGraph; ++i)
    {
        int j = IndexOfElement(S, false);
        int u = j++;

        while(j < sizeOfGraph)
        {
            if(!S[j] && d[j] < d[u])
            {
                u = j;
            }

            ++j;
        }

        S[u] = true;

        for(int y = 0; y < (*m_adjList)[u].size(); ++y)
        {
            int vertex = (*m_adjList)[u][y];

            if(!S[vertex] && d[vertex] > d[u] + m_weights[u][y])
            {
                d[vertex] = d[u] + m_weights[u][y];
                p[vertex] = u;
            }
        }
    }

    return d;
}

int StronglyConnectedDiGraph::IndexOfElement(const std::vector<bool> & vec, const bool element) const
{
    int i;

    for(i = 0; i < vec.size(); ++i)
    {
        if(vec[i] == element)
            break;
    }

    return i;
}

void StronglyConnectedDiGraph::PrintMatrix(const std::vector<std::vector<int>> & matrix)
{
    for(int i = 0; i < matrix.size(); ++i)
    {
        std::cout << i + 1 << ": ";

        for(int j = 0; j < matrix[i].size(); ++j)
        {
            std::cout << std::setw(4) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout <<std::endl;
}

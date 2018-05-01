//
// Created by piotr on 01.05.18.
//

#include <vector>
#include <IncMatrix.h>
#include <iostream>
#include <iomanip>
#include <fstream>


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
    PrintToFile();

    std::cout << "Macierz Incydencji" << std::endl;

    for(auto & row : m_incMatrix)
    {
        for(auto & item : row)
        {
            std::cout << std::setw(2) << item << " ";
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void IncMatrix::PrintToFile() const
{
    ////////// Macierz incydencji //////////
    std::ofstream incMatrixFile;

    if (!incMatrixFile.is_open())
    {
        incMatrixFile.open("MacierzIncydencji.txt", std::ios::out);

        if(!incMatrixFile)
        {
            std::cerr << "Failed to open " << "MacierzIncydencji.txt" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    incMatrixFile << "MI" << std::endl;

    for(auto & row : m_incMatrix)
    {
        for(auto & item : row)
        {
            incMatrixFile << std::setw(2) << item << " ";
        }

        incMatrixFile << std::endl;
    }
    incMatrixFile << std::endl;

    incMatrixFile.close();
}

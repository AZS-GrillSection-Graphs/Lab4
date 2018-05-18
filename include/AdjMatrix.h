#ifndef GRAPHS4_ADJMATRIX_H
#define GRAPHS4_ADJMATRIX_H


#include <vector>


class AdjList;
class IncMatrix;


class AdjMatrix
{
public:
    AdjMatrix(const int numberOfVertices, const double probability);
    ~AdjMatrix() = default;
    void Print() const;
    AdjList ConvertToAdjList() const;
    IncMatrix ConvertToIncMatrix() const;
    void ShowAllRepresentations() const;

private:
    std::vector<std::vector<int>> m_adjMatrix;
};

#endif //GRAPHS4_ADJMATRIX_H

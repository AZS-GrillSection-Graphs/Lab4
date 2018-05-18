#ifndef GRAPHS4_COMPONENT_H
#define GRAPHS4_COMPONENT_H


#include <vector>


class Component
{
public:
    Component(std::vector<int> comp = std::vector<int>(0)) : m_component(comp) {}

    void Print() const;
    void PrintOriginIndex() const;
    bool IsElementInComponent(const int & element) const;
    Component FindBiggestComponent() const;
    int IndexOfElement(const int element) const;

    void emplace_back(const int value);
    unsigned size() const;
    int operator[] (const int index) const;
    void sort();

private:
    std::vector<int> m_component;
};


#endif //GRAPHS4_COMPONENT_H

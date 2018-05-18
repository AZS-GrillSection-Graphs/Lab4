#include <iostream>
#include <map>
#include <algorithm>

#include "Component.h"


void Component::Print() const
{
    for(auto & item : m_component)
    {
        std::cout << item + 1 << " ";
    }
    std::cout << std::endl;
}

void Component::PrintOriginIndex() const
{
    for(auto & item : m_component)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

bool Component::IsElementInComponent(const int &element) const
{
    bool CompHaveElement = false;

    for(auto item : m_component)
    {
        if(item == element)
        {
            CompHaveElement = true;
            break;
        }
    }

    return CompHaveElement;
}

Component Component::FindBiggestComponent() const
{
    int max = 0;
    int most_common = -1;

    std::map<int, int> m;

    for(auto vi = m_component.begin(); vi != m_component.end(); vi++)
    {
        m[*vi]++;

        if (m[*vi] > max)
        {
            max = m[*vi];
            most_common = *vi;
        }
    }

    Component biggest;

    for(unsigned i = 0; i < m_component.size(); ++i)
    {
        if(m_component[i] == most_common)
            biggest.emplace_back(i);
    }

    std::cout << "Biggest Component: " << std::endl;
    biggest.Print();

    return biggest;
}

int Component::IndexOfElement(const int element) const
{
    int i;

    for(i = 0; i < m_component.size(); ++i)
    {
        if(m_component[i] == element)
            break;
    }

    return i;
}

void Component::emplace_back(const int value)
{
    m_component.emplace_back(value);
}

unsigned Component::size() const
{
    return m_component.size();
}

int Component::operator[](const int index) const
{
    return m_component[index];
}

void Component::sort()
{
    std::sort(m_component.begin(), m_component.end());
}

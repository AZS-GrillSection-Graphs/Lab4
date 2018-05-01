//
// Created by piotr on 01.05.18.
//

#ifndef GRAPHS4_GRAPHREPRESENTATION_H
#define GRAPHS4_GRAPHREPRESENTATION_H

#include <string>

class GraphRepresentation
{
public:
    virtual ~GraphRepresentation() = default;
    virtual void Print() const = 0;
    virtual const GraphRepresentation * Convert(std::string ReprName) const = 0;
    virtual void ShowAllRepresentations() const = 0;


    int iRand(const int min, const int max);
};


#endif //GRAPHS4_GRAPHREPRESENTATION_H

//
// Created by piotr on 01.05.18.
//

#ifndef GRAPHS4_GRAPHREPRESENTATION_H
#define GRAPHS4_GRAPHREPRESENTATION_H


class GraphRepresentation
{
public:
    ~GraphRepresentation() = default;
    virtual void Print() const = 0;
    int iRand(const int min, const int max);


};


#endif //GRAPHS4_GRAPHREPRESENTATION_H

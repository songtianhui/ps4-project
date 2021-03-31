//
// Created by sth on 3/12/21.
//

#ifndef GRAPHLIBRARY_WEIGHTEDEDGE_H
#define GRAPHLIBRARY_WEIGHTEDEDGE_H
#include <DataStructures/Edge.h>

template <typename T>
class WeightedEdge {
private:
    int source;
    int destination;
    T weight;

public:
    WeightedEdge(int source, int destination, T weight) {
        this->source = source;
        this->destination = destination;
        this->weight = weight;
    }

    virtual ~WeightedEdge() {}

public:
    T GetWeight() const {
        return weight;
    }

    int GetSource() const {
        return source;
    }

    int GetDestination() const {
        return destination;
    }

};

#endif //GRAPHLIBRARY_WEIGHTEDEDGE_H

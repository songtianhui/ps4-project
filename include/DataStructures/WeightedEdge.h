//
// Created by sth on 3/12/21.
//

#ifndef GRAPHLIBRARY_WEIGHTEDEDGE_H
#define GRAPHLIBRARY_WEIGHTEDEDGE_H
#include <DataStructures/Edge.h>

class WeightedEdge : public Edge {
private:
    int weight;

public:
    WeightedEdge(int source, int destination, int weight);

    int GetWeight() const;

};

#endif //GRAPHLIBRARY_WEIGHTEDEDGE_H

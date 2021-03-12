//
// Created by sth on 3/12/21.
//

#include <Edge.h>
#ifndef GRAPHLIBRARY_WEIGHTEDEDGE_H
#define GRAPHLIBRARY_WEIGHTEDEDGE_H

class WeightedEdge : public Edge {
private:
    int weight;

public:
    WeightedEdge(int source, int destination, int weight);
    int GetWeight();
};

#endif //GRAPHLIBRARY_WEIGHTEDEDGE_H

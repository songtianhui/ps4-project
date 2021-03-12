//
// Created by sth on 3/12/21.
//

#include <DataStructures/Edge.h>
#ifndef GRAPHLIBRARY_WEIGHTEDEDGE_H
#define GRAPHLIBRARY_WEIGHTEDEDGE_H

class WeightedEdge : public Edge {
private:
    int weight;

public:
    WeightedEdge(int source, int destination, int weight);

    int GetWeight() const;

    std::vector<WeightedEdge> GetEdges() const;

    std::vector<WeightedEdge> GetIncomingEdges(int vertex) const;

    std::vector<WeightedEdge> GetOutgoingEdges(int vertex) const;
};

#endif //GRAPHLIBRARY_WEIGHTEDEDGE_H

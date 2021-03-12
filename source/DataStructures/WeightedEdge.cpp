//
// Created by sth on 3/12/21.
//

#include <DataStructures/WeightedEdge.h>

WeightedEdge::WeightedEdge(int source, int destination, int weight) : Edge(source, destination) {
    this->weight = weight;
}

int WeightedEdge::GetWeight() {
    return weight;
}

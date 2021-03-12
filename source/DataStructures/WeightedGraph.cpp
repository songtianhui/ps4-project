//
// Created by sth on 3/12/21.
//

#include <DataStructures/WeightedGraph.h>
#include <DataStructures/WeightedEdge.h>
#include <cassert>

WeightedGraph::WeightedGraph() : Graph(){
    weight.clear();
}

WeightedGraph::~WeightedGraph() {}

bool WeightedGraph::AddEdge(int vertex1, int vertex2, int weight) {
    bool succ = Graph::AddEdge(vertex1, vertex2);
    if (succ) {
        this->weight[std::make_pair(mp[vertex1], mp[vertex2])] = weight;
        return true;
    }
    return false;
}

int WeightedGraph::GetWeight(int vertex1, int vertex2) const {
    auto it1 = mp.find(vertex1);
    auto it2 = mp.find(vertex2);
    if (it1 == mp.end() || it2 == mp.end()) return 0;
    auto it = weight.find(std::make_pair(it1->second, it2->second));
    assert(it != weight.end());
    return it->second;
}
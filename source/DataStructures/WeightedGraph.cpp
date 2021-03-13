//
// Created by sth on 3/12/21.
//

#include <DataStructures/WeightedGraph.h>
#include <cassert>

WeightedGraph::WeightedGraph() : Graph(){
    weights.clear();
}

WeightedGraph::~WeightedGraph() {}

bool WeightedGraph::AddEdge(int vertex1, int vertex2, int weight) {
    bool succ = Graph::AddEdge(vertex1, vertex2);
    if (succ) {
        weights[std::make_pair(vertex1, vertex2)] = weight;
        return true;
    }
    return false;
}

bool WeightedGraph::RemoveEdge(int vertex1, int vertex2) {
    bool succ = Graph::RemoveEdge(vertex1, vertex2);
    if (succ) {
        auto it = weights.find(std::make_pair(vertex1, vertex2));
        weights.erase(it);
        return true;
    }
    return false;
}

int WeightedGraph::GetWeight(int vertex1, int vertex2) const {
    auto it = weights.find(std::make_pair(vertex1, vertex2));
    if (it != weights.end()) return it->second;
    return 0;

    // auto it1 = mp.find(vertex1);
    // auto it2 = mp.find(vertex2);
    // if (it1 == mp.end() || it2 == mp.end() || !ContainsEdge(vertex1, vertex2)) return INF;
    // auto it = weights.find(std::make_pair(it1->second, it2->second));
    // assert(it != weights.end());
    // return it->second;
}

std::vector<WeightedEdge> WeightedGraph::giveweight(std::vector<Edge> *es) const {
    std::vector<WeightedEdge> Wedges;
    for (auto &e : *es) {
        const int s = e.GetSource();
        const int d = e.GetDestination();

        int w = GetWeight(s, d);
        Wedges.emplace_back(WeightedEdge(s, d, w));
    }
    return Wedges;
}

std::vector<WeightedEdge> WeightedGraph::GetEdges() const {
    std::vector<Edge> alledges = Graph::GetEdges();
    std::vector<WeightedEdge> allwedges;
    allwedges = giveweight(&alledges);
    return allwedges;
}

std::vector<WeightedEdge> WeightedGraph::GetIncomingEdges(int vertex) const {
    std::vector<Edge> in = Graph::GetIncomingEdges(vertex);
    std::vector<WeightedEdge> inw = giveweight(&in);
    return inw;
}

std::vector<WeightedEdge> WeightedGraph::GetOutgoingEdges(int vertex) const {
    std::vector<Edge> out = Graph::GetOutgoingEdges(vertex);
    std::vector<WeightedEdge> outw = giveweight(&out);
    return outw;
}
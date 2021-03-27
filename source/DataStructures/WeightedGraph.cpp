//
// Created by sth on 3/12/21.
//

#include <DataStructures/WeightedGraph.h>
//
//WeightedGraph::WeightedGraph() : Graph(){
//    memset(weights, 0, sizeof(weights));
//}
//
//WeightedGraph::~WeightedGraph() {}
//
//bool WeightedGraph::AddEdge(int vertex1, int vertex2, int weight) {
//    bool succ = Graph::AddEdge(vertex1, vertex2);
//    if (succ) {
//        vertex1 = Getmap(vertex1);
//        vertex2 = Getmap(vertex2);
//        weights[vertex1][vertex2] = weight;
//        return true;
//    }
//    return false;
//}
//
//
//int WeightedGraph::GetWeight(int vertex1, int vertex2) const {
//    vertex1 = Getmap(vertex1);
//    vertex2 = Getmap(vertex2);
//    return weights[vertex1][vertex2];
//}
//
//std::vector<WeightedEdge> WeightedGraph::giveweight(std::vector<Edge> *es) const {
//    std::vector<WeightedEdge> Wedges;
//    for (auto &e : *es) {
//        const int s = e.GetSource();
//        const int d = e.GetDestination();
//        assert(ContainsVertex(s) && ContainsVertex(d));
//
//        int w = GetWeight(s, d);
//        Wedges.emplace_back(WeightedEdge(s, d, w));
//    }
//    return Wedges;
//}
//
//std::vector<WeightedEdge> WeightedGraph::GetEdges() const {
//    std::vector<Edge> alledges = Graph::GetEdges();
//    std::vector<WeightedEdge> allwedges;
//    allwedges = giveweight(&alledges);
//    return allwedges;
//}
//
//std::vector<WeightedEdge> WeightedGraph::GetIncomingEdges(int vertex) const {
//    std::vector<Edge> in = Graph::GetIncomingEdges(vertex);
//    std::vector<WeightedEdge> inw = giveweight(&in);
//    return inw;
//}
//
//std::vector<WeightedEdge> WeightedGraph::GetOutgoingEdges(int vertex) const {
//    std::vector<Edge> out = Graph::GetOutgoingEdges(vertex);
//    std::vector<WeightedEdge> outw = giveweight(&out);
//    return outw;
//}

WeightedGraph::WeightedGraph() : Generic<WeightedEdge>() {
    weight.clear();
}

WeightedGraph::~WeightedGraph() {}

bool WeightedGraph::AddEdge(int vertex1, int vertex2, int weight) {
    WeightedEdge e = WeightedEdge(vertex1, vertex2, weight);
    this->weight[std::make_pair(vertex1, vertex2)] = weight;
    return InsertEdge(e);
}

int WeightedGraph::GetWeight(int vertex1, int vertex2) {
    if (!ContainsEdge(vertex1, vertex2)) return 0;
    return weight[std::make_pair(vertex1, vertex2)];
}
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
    bool succ = InsertEdge(e);
    if (succ) {
        this->weight[std::make_pair(vertex1, vertex2)] = weight;
    }
    return succ;
}

int WeightedGraph::GetWeight(int vertex1, int vertex2) const {
    if (!ContainsEdge(vertex1, vertex2)) return 0;
    auto it = weight.find(std::make_pair(vertex1, vertex2));
    assert(it != weight.end());
    return it->second;
}

//std::vector<WeightedEdge> WeightedGraph::GetEdges() const {
//    std::vector<std::pair<int, int> > pairs = ObtainEdges();
//    std::vector<WeightedEdge> alledges;
//    for (std::pair<int, int> &e : pairs) {
//        alledges.push_back(WeightedEdge(e.first, e.second, GetWeight(e.first, e.second)));
//    }
//    return alledges;
//}
//
//std::vector<WeightedEdge> WeightedGraph::GetIncomingEdges(int vertex) const {
//    std::vector<std::pair<int, int> > pairs = ObtainIncomingEdges(vertex);
//    std::vector<WeightedEdge> inedges;
//    for (std::pair<int, int> &e : pairs) {
//        inedges.push_back(WeightedEdge(e.first, e.second, GetWeight(e.first, e.second)));
//    }
//    return inedges;
//}
//
//std::vector<WeightedEdge> WeightedGraph::GetOutgoingEdges(int vertex) const {
//    std::vector<std::pair<int, int> > pairs = ObtainOutgoingEdges(vertex);
//    std::vector<WeightedEdge> outedges;
//    for (std::pair<int, int> &e : pairs) {
//        outedges.push_back(WeightedEdge(e.first, e.second, GetWeight(e.first, e.second)));
//    }
//    return outedges;
//}
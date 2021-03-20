//
// Created by sth on 3/20/21.
//

#include <DataStructures/UndirectedWeightedGraph.h>

UndirectedWeightedGraph::UndirectedWeightedGraph() : UndirectedGraph(){
    memset(weights, 0, sizeof(weights));
}

UndirectedWeightedGraph::~UndirectedWeightedGraph() {}

bool UndirectedWeightedGraph::AddEdge(int vertex1, int vertex2, int weight) {
    bool succ1 = UndirectedGraph::AddEdge(vertex1, vertex2);
    bool succ2 = UndirectedGraph::AddEdge(vertex2, vertex1);

    if (succ1 && succ2) {
        vertex1 = Getmap(vertex1);
        vertex2 = Getmap(vertex2);
        weights[vertex1][vertex2] = weight;
        weights[vertex2][vertex1] = weight;
        return true;
    }
    return false;
}


int UndirectedWeightedGraph::GetWeight(int vertex1, int vertex2) const {
    vertex1 = Getmap(vertex1);
    vertex2 = Getmap(vertex2);
    return weights[vertex1][vertex2];
}

std::vector<WeightedEdge> UndirectedWeightedGraph::giveweight(std::vector<Edge> *es) const {
    std::vector<WeightedEdge> Wedges;
    for (auto &e : *es) {
        const int s = e.GetSource();
        const int d = e.GetDestination();
        assert(ContainsVertex(s) && ContainsVertex(d));

        int w = GetWeight(s, d);
        Wedges.emplace_back(WeightedEdge(s, d, w));
    }
    return Wedges;
}

std::vector<WeightedEdge> UndirectedWeightedGraph::GetEdges() const {
    std::vector<Edge> alledges = UndirectedGraph::GetEdges();
    std::vector<WeightedEdge> allwedges;
    allwedges = giveweight(&alledges);
    return allwedges;
}

std::vector<WeightedEdge> UndirectedWeightedGraph::GetIncomingEdges(int vertex) const {
    std::vector<Edge> in = UndirectedGraph::GetIncomingEdges(vertex);
    std::vector<WeightedEdge> inw = giveweight(&in);
    return inw;
}

std::vector<WeightedEdge> UndirectedWeightedGraph::GetOutgoingEdges(int vertex) const {
    std::vector<Edge> out = UndirectedGraph::GetOutgoingEdges(vertex);
    std::vector<WeightedEdge> outw = giveweight(&out);
    return outw;
}
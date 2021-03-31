//
// Created by sth on 3/12/21.
//

#ifndef GRAPHLIBRARY_WEIGHTEDGRAPH_H
#define GRAPHLIBRARY_WEIGHTEDGRAPH_H

#include <DataStructures/Generic.h>
#include <DataStructures/WeightedEdge.h>
#include <cstring>

//
//class WeightedGraph : public Graph {
//private:
//    int weights[MAXV][MAXV];
//
//private:
//    std::vector<WeightedEdge> giveweight(std::vector<Edge> *es) const;
//
//public:
//    WeightedGraph();
//
//    ~WeightedGraph();
//
//public:
//    bool AddEdge(int vertex1, int vertex2, int weight);  //添加了权重参数
//
//public:
//    int GetWeight(int vertex1, int vertex2) const;  //查询v1指向v2的边的权重，如果这条边不存在则属于UB
//
//    std::vector<WeightedEdge> GetEdges() const;
//
//    std::vector<WeightedEdge> GetIncomingEdges(int vertex) const;
//
//    std::vector<WeightedEdge> GetOutgoingEdges(int vertex) const;
//
//};

template <typename T>
class WeightedGraph : public Generic<WeightedEdge<T> > {
private:
    std::map<std::pair<int, int>, T> weight;

public:
    WeightedGraph() {
        weight.clear();
    }

    virtual ~WeightedGraph() {}

public:
    T GetWeight(int vertex1, int vertex2) const {
        if (!Generic<WeightedGraph<T> >::ContainsEdge(vertex1, vertex2)) return 0;
        auto it = weight.find(std::make_pair(vertex1, vertex2));
        assert(it != weight.end());
        return it->second;
    }

    bool AddEdge(int vertex1, int vertex2, T weight) {
        WeightedEdge<T> e = WeightedEdge<T>(vertex1, vertex2, weight);
        bool succ = InsertEdge(e);
        if (succ) {
            this->weight[std::make_pair(vertex1, vertex2)] = weight;
        }
        return succ;
    }

//    std::vector<WeightedEdge> GetEdges() const;
//
//    std::vector<WeightedEdge> GetIncomingEdges(int vertex) const;
//
//    std::vector<WeightedEdge> GetOutgoingEdges(int vertex) const;
};

#endif //GRAPHLIBRARY_WEIGHTEDGRAPH_H

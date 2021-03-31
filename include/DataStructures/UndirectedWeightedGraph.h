//
// Created by sth on 3/20/21.
//

#ifndef GRAPHLIBRARY_UNDIRECTEDWEIGHTEDGRAPH_H
#define GRAPHLIBRARY_UNDIRECTEDWEIGHTEDGRAPH_H

//#include <DataStructures/UndirectedGraph.h>
//#include <DataStructures/WeightedGraph.h>
//
//class UndirectedWeightedGraph : public UndirectedGraph {
//private:
//    int weights[MAXV][MAXV];
//
//private:
//    std::vector<WeightedEdge> giveweight(std::vector<Edge> *es) const;
//
//public:
//    UndirectedWeightedGraph();
//
//    ~UndirectedWeightedGraph();
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

#include <DataStructures/UndirectedGeneric.h>
#include <DataStructures/WeightedEdge.h>

template <typename T>
class UndirectedWeightedGraph : public UndirectedGeneric<WeightedEdge<T> > {
private:
    std::map<std::pair<int,int>, T> weight;

public:
    UndirectedWeightedGraph() {
        weight.clear();
    }
    virtual ~UndirectedWeightedGraph() {}

public:
    bool AddEdge(int vertex1, int vertex2, T weight) {
        bool succ1 = UndirectedGeneric<WeightedEdge<T> >::InsertEdge(WeightedEdge<T>(vertex1, vertex2, weight));
        bool succ2 = true;

        if (succ1) {
            this->weight[std::make_pair(vertex1, vertex2)] = weight;
            this->weight[std::make_pair(vertex2, vertex1)] = weight;
            if (vertex1 != vertex2) {
                succ2 = UndirectedWeightedGraph<WeightedEdge<T> >::InsertEdge(WeightedEdge<T>(vertex2, vertex1, weight));
                if (succ1 && succ2) this->NR_edges--;
            }
        }

        return succ1 && succ2;
    }

    T GetWeight(int vertex1, int vertex2) const {
        auto it = weight.find(std::make_pair(vertex1, vertex2));
        if (it == weight.end()) return 0;
        else return it->second;
    }

};
#endif //GRAPHLIBRARY_UNDIRECTEDWEIGHTEDGRAPH_H

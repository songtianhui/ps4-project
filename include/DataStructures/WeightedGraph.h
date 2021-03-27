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

class WeightedGraph : public Generic<WeightedEdge> {
private:
    std::map<std::pair<int, int>, int> weight;

public:
    WeightedGraph();
    ~WeightedGraph();

public:
    int GetWeight(int vertex1, int vertex2);

    bool AddEdge(int vertex1, int vertex2, int weight);
};

#endif //GRAPHLIBRARY_WEIGHTEDGRAPH_H

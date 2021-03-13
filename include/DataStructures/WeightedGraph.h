//
// Created by sth on 3/12/21.
//

#ifndef GRAPHLIBRARY_WEIGHTEDGRAPH_H
#define GRAPHLIBRARY_WEIGHTEDGRAPH_H

#include <DataStructures/Graph.h>
#include <DataStructures/WeightedEdge.h>
#include <map>
#include <vector>

class WeightedGraph : public Graph {
private:
    std::map<std::pair<int, int>, int> weights;

private:
    std::vector<WeightedEdge> giveweight(std::vector<Edge> *es) const;
public:
    WeightedGraph();

    ~WeightedGraph();

public:
    bool AddEdge(int vertex1, int vertex2, int weight);  //添加了权重参数

    bool RemoveEdge(int vertex1, int vertex2);
public:
    int GetWeight(int vertex1, int vertex2) const;  //查询v1指向v2的边的权重，如果这条边不存在则属于UB

    std::vector<WeightedEdge> GetEdges() const;

    std::vector<WeightedEdge> GetIncomingEdges(int vertex) const;

    std::vector<WeightedEdge> GetOutgoingEdges(int vertex) const;

};

#endif //GRAPHLIBRARY_WEIGHTEDGRAPH_H

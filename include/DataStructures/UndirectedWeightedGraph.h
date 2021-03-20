//
// Created by sth on 3/20/21.
//

#ifndef GRAPHLIBRARY_UNDIRECTEDWEIGHTEDGRAPH_H
#define GRAPHLIBRARY_UNDIRECTEDWEIGHTEDGRAPH_H

#include <DataStructures/WeightedGraph.h>
#include <DataStructures/UndirectedGraph.h>

class UndirectedWeightedGraph : public UndirectedGraph {
private:
    int weights[MAXV][MAXV];

private:
    std::vector<WeightedEdge> giveweight(std::vector<Edge> *es) const;

public:
    UndirectedWeightedGraph();

    ~UndirectedWeightedGraph();

public:
    bool AddEdge(int vertex1, int vertex2, int weight);  //添加了权重参数

public:
    int GetWeight(int vertex1, int vertex2) const;  //查询v1指向v2的边的权重，如果这条边不存在则属于UB

    std::vector<WeightedEdge> GetEdges() const;

    std::vector<WeightedEdge> GetIncomingEdges(int vertex) const;

    std::vector<WeightedEdge> GetOutgoingEdges(int vertex) const;


#endif //GRAPHLIBRARY_UNDIRECTEDWEIGHTEDGRAPH_H

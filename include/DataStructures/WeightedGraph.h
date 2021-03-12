//
// Created by sth on 3/12/21.
//

#ifndef GRAPHLIBRARY_WEIGHTEDGRAPH_H
#define GRAPHLIBRARY_WEIGHTEDGRAPH_H

#include <DataStructures/Graph.h>
#include <map>

class WeightedGraph : public Graph {
private:
    std::map<std::pair<int, int>, int> weight;

public:
    WeightedGraph();

    ~WeightedGraph();

public:
    bool AddEdge(int vertex1, int vertex2, int weight);  //添加了权重参数

public:
    int GetWeight(int vertex1, int vertex2) const;  //查询v1指向v2的边的权重，如果这条边不存在则属于UB

};

#endif //GRAPHLIBRARY_WEIGHTEDGRAPH_H

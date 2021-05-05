//
// Created by sth on 2021/5/5.
//

#include <Algorithms/FloydShortestPaths.h>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>

UndirectedWeightedGraph<int> g;

void init_g() {
    assert(g.AddVertex(1) == true);
    assert(g.AddVertex(1000) == true);
    assert(g.AddVertex(99999) == true);
    assert(g.AddVertex(0) == true);
    assert(g.AddVertex(-114514) == true);
    assert(g.AddVertex(99999) == false);
    assert(g.AddVertex(0) == false);
    assert(g.RemoveVertex(1) == true);
    assert(g.RemoveVertex(1) == false);
    assert(g.AddVertex(1) == true);


    assert(g.AddEdge(1, 1000, 114514) == true);
    assert(g.AddEdge(0, 1000, 100) == true);
    assert(g.AddEdge(-114514, 0, -100) == true);
    assert(g.AddEdge(99999, 0, 0) == true);
    assert(g.AddEdge(1000, 99999, 250) == true);
    assert(g.AddEdge(99999, 1, 99) == true);
    assert(g.AddEdge(1000, 1000, 10) == true);
}

int main() {
    init_g();

    return 0;
}


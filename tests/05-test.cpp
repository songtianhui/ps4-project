//
// Created by sth on 2021/4/9.
//

#include <Algorithms/BreadthFirstSearcher.h>
#include <Algorithms/DepthFirstSearcher.h>
#include <DataStructures/Graph.h>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>

Graph g;

void print(int x) {
    printf("%d\n", x);
}

bool cond(int x) {
    return x > 100;
}

int main() {
    assert(g.AddVertex(1) == true);
    assert(g.AddVertex(1000) == true);
    assert(g.AddVertex(99999) == true);
    assert(g.AddVertex(0) == true);
    assert(g.AddVertex(-114514) == true);

    assert(g.AddEdge(1, 1000) == true);
    assert(g.AddEdge(0, 1000) == true);
    assert(g.AddEdge(-114514, 0) == true);
    assert(g.AddEdge(99999, 0) == true);
    assert(g.AddEdge(1000, 99999) == true);
    assert(g.AddEdge(99999, 1) == true);
    assert(g.AddEdge(1000, 1000) == true);
    assert(g.AddEdge(99999, -114514) == true);
    assert(g.AddEdge(0, -114514) == true);

    DepthFirstSearcher<Graph>::VisitAllVertices(&g, 10, &print);
    printf("first: %d\n", DepthFirstSearcher<Graph>::FindFirstVertex(&g, 0, &cond));

    return 0;
}

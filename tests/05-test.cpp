//
// Created by sth on 2021/4/9.
//

#include <iostream>
#include <Algorithms/BreadthFirstSearcher.h>
#include <Algorithms/DepthFirstSearcher.h>
#include <DataStructures/Graph.h>
#include <DataStructures/UndirectedGraph.h>
#include <DataStructures/WeightedGraph.h>
#include <DataStructures/UndirectedWeightedGraph.h>

UndirectedGraph g;

void print(int x) {
    printf("%d\n", x);
}

bool cond(int x) {
    return x == 100;
}

int main() {
    assert(g.AddVertex(1) == true);
    assert(g.AddVertex(1000) == true);
    assert(g.AddVertex(99999) == true);
    assert(g.AddVertex(0) == true);
    assert(g.AddVertex(-114514) == true);

//    assert(g.AddEdge(1, 1000) == true);
    assert(g.AddEdge(0, 1000) == true);
    assert(g.AddEdge(-114514, 0) == true);
    assert(g.AddEdge(99999, 0) == true);
    assert(g.AddEdge(1000, 99999) == true);
    assert(g.AddEdge(99999, 1) == true);
    assert(g.AddEdge(1000, 1000) == true);
    assert(g.AddEdge(99999, -114514) == true);
//    assert(g.AddEdge(0, -114514) == true);

    int start = 99999;
    BreadthFirstSearcher<UndirectedGraph>::VisitAllVertices(&g, start, &print);
    printf("first: %d\n", BreadthFirstSearcher<UndirectedGraph>::FindFirstVertex(&g, start, &cond));

    DepthFirstSearcher<UndirectedGraph>::VisitAllVertices(&g, start, &print);
    printf("first: %d\n", DepthFirstSearcher<UndirectedGraph>::FindFirstVertex(&g, start, &cond));


    return 0;
}

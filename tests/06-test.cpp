//
// Created by sth on 2021/4/21.
//


#include <Algorithms/DijkstraShortestPaths.h>
#include <DataStructures/WeightedGraph.h>

WeightedGraph<double> g;

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

    DijkstraShortestPaths<WeightedGraph, double> ssp(&g, 1);
    int dst = 1000;
    if (ssp.HasPathTo(dst)) printf("HasPath to %d: %lf\n", dst, ssp.HasPathTo(dst));
    printf("distance to %d: %lf\n", dst, ssp.TryGetDistanceTo(dst));
    printf("path to %d:\n", dst);
    for (int i : ssp.TryGetShortestPathTo(dst).value()) {
        printf("%d--", i);
    }
    printf("\n");

    printf("Successful!\n");
}


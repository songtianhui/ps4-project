//
// Created by sth on 2021/4/25.
//


#include <Algorithms/BellmanFordShortestPaths.h>
#include <DataStructures/UndirectedWeightedGraph.h>
#include <DataStructures/WeightedGraph.h>

struct no_default
{
    no_default () = delete;
};

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
    assert(g.AddEdge(-114514, 0, 100) == true);
    assert(g.AddEdge(99999, 0, 0) == true);
    assert(g.AddEdge(1000, 99999, 250) == true);
    assert(g.AddEdge(99999, 1, 99) == true);
    assert(g.AddEdge(1000, 1000, 10) == true);
}

int main() {
    init_g();

    BellmanFordShortestPaths<WeightedGraph<int>> ssp(&g, 99999);
    int dst = 100;
    if (ssp.HasPathTo(dst)) printf("HasPath to %d: %d\n", dst, ssp.HasPathTo(dst));
    if (ssp.TryGetDistanceTo(dst) != std::nullopt) printf("distance to %d: %d\n", dst, ssp.TryGetDistanceTo(dst).value());
    else printf("Infinity\n");
    printf("path to %d:\n", dst);
    std::vector<int> v = ssp.TryGetShortestPathTo(dst) == std::nullopt ? std::vector<int>() : ssp.TryGetShortestPathTo(dst).value();
    for (int &i : v) {
        printf("%d--", i);
    }
    printf("\n");

    printf("Successful!\n");

    return 0;
}

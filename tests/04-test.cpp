//
// Created by sth on 3/31/21.
//

#include <DataStructures/UndirectedWeightedGraph.h>
#include <DataStructures/UndirectedGraph.h>

UndirectedWeightedGraph g;

void printvector(std::vector<WeightedEdge> *wes) {
    for (auto &e : *wes) {
        printf("w(%d, %d) = %d\n", e.GetSource(), e.GetDestination(), e.GetWeight());
    }
}

void printw(int s, int d) {
    printf("w(%d, %d) = %d\n", s, d ,g.GetWeight(s,d));
}


int main() {
    // AddVertice
    assert(g.AddVertex(1) == true);
    assert(g.AddVertex(1000) == true);
    assert(g.AddVertex(99999) == true);
    assert(g.AddVertex(0) == true);
    assert(g.AddVertex(-114514) == true);
    assert(g.AddVertex(99999) == false);
    assert(g.AddVertex(0) == false);
    assert(g.RemoveVertex(1) == true);
    assert(g.AddVertex(1) == true);

    printf("NR_vertices = %d\n", g.CountVertices());

    assert(g.AddEdge(1, 1000, 114514) == true);
    assert(g.AddEdge(0, 1000, 100) == true);
    assert(g.AddEdge(-114514, 0, -100) == true);
    assert(g.AddEdge(99999, 0, 0) == true);
    assert(g.AddEdge(1000, 99999, 250) == true);
    printf("NR_edges = %d\n", g.CountEdges());
    assert(g.AddEdge(1000, 1, 800) == false);
    printf("NR_edges = %d\n", g.CountEdges());
    assert(g.AddEdge(99999, 1, 99) == true);
    printf("NR_edges = %d\n", g.CountEdges());
    assert(g.AddEdge(1000, 1000, 10) == true);
    printf("NR_edges = %d\n", g.CountEdges());
    assert(g.AddEdge(1, 1000, 1) == false);
    printf("NR_edges = %d\n", g.CountEdges());
    assert(g.AddEdge(1, 2, 12) == false);
    assert(g.AddEdge(0, -114514, 0) == false);
    assert(g.RemoveEdge(0, -114514) == true);
    assert(g.RemoveEdge(1, 100) == false);
    assert(g.RemoveEdge(1000, -114514) == false);
    printf("NR_edges = %d\n", g.CountEdges());
    assert(g.AddEdge(0, -114514, -100) == true);
    printf("NR_edges = %d\n", g.CountEdges());

    assert(g.ContainsEdge(1, 1000) == true);
    assert(g.ContainsEdge(1000, 1) == true);
    assert(g.ContainsEdge(0, 1000) == true);
    assert(g.ContainsEdge(1000, 0) == true);
    assert(g.ContainsEdge(0, -114514) == true);
    assert(g.ContainsEdge(-114514, 0) == true);
    assert(g.ContainsEdge(0, 99999) == true);
    assert(g.ContainsEdge(99999, 0) == true);
    assert(g.ContainsEdge(1000, 99999) == true);
    assert(g.ContainsEdge(99999, 1000) == true);
    assert(g.ContainsEdge(1, 99999) == true);
    assert(g.ContainsEdge(99999, 1) == true);
    assert(g.ContainsEdge(1000, 1000) == true);
    assert(g.ContainsEdge(100, 1000) == false);



    printf("OK!\n");

}
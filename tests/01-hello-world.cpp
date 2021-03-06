#include <cassert>
#include <cstdio>
#include <DataStructures/WeightedGraph.h>

using namespace std;

WeightedGraph g;

void print_edge() {
    printf("all edges: \n");
    std::vector<WeightedEdge> tmp = g.GetEdges();
    for (Edge e: tmp) {
        printf("(%d, %d)\n", e.GetSource(), e.GetDestination());
    }
}

void print_vertex() {
    printf("all vertices: \n");
    std:
    vector<int> tmp = g.GetVertices();
    for (int e: tmp) {
        printf("%d\n", e);
    }
}

void v1_nei() {
    printf("v1 has neighbours: \n");
    for (int i: g.GetNeighbors(1)) {
        printf("%d\n", i);
    }
}

int main() {
    assert(g.GetDegree(2) == 0);
    assert(g.CountVertices() == 0);
    assert(g.CountEdges() == 0);
    assert(g.GetIncomingEdges(3).size() == 0);
    assert(g.RemoveEdge(1, 2) == false);
    assert(g.ContainsEdge(5, 6) == false);
    assert(g.ContainsVertex(2) == false);

    assert(g.AddVertex(1) == true);
    assert(g.GetNeighbors(1).size() == 0);
    assert(g.ContainsVertex(1) == true);
    assert(g.CountVertices() == 1);
    assert(g.CountEdges() == 0);

    assert(g.AddVertex(2) == true);
    assert(g.AddVertex(3) == true);
    assert(g.AddVertex(3) == false);
    assert(g.AddVertex(4) == true);
    assert(g.ContainsVertex(4) == true);
    assert(g.RemoveVertex(4) == true);
    assert(g.ContainsVertex(4) == false);
    assert(g.CountVertices() == 3);
    assert(g.ContainsVertex(4) == false);
    assert(g.RemoveVertex(5) == false);
    assert(g.AddVertex(5) == true);

    assert(g.AddEdge(1, 2, 1) == true);
    assert(g.AddEdge(1, 2, 2) == false);
    assert(g.AddEdge(1, 3, 3) == true);
    assert(g.AddEdge(2, 6, 4) == false);
    assert(g.ContainsEdge(1, 2) == true);
    assert(g.ContainsEdge(2, 6) == false);

    assert(g.GetDegree(1) == 2);
    assert(g.GetIncomingEdges(1).empty());
    assert(g.GetOutgoingEdges(1).size() == 2);
    assert(g.GetNeighbors(1).size() == 2);
    assert(g.GetNeighbors(2).empty());

    assert(g.AddVertex(9) == true);
    assert(g.AddVertex(15) == true);
    assert(g.AddEdge(1, 5, 5) == true);
    assert(g.AddEdge(1, 9, 6) == true);
    assert(g.AddEdge(15, 1, 7) == true);

    assert(g.RemoveEdge(1, 5) == true);

    print_vertex();
    print_edge();
    v1_nei();

    assert(g.AddEdge(2, 9, 8) == true);
    assert(g.AddEdge(9, 5, 9) == true);
    assert(g.AddEdge(5, 5, 10) == true);

    print_vertex();
    print_edge();
    v1_nei();

    assert(g.RemoveVertex(9) == true);

    print_vertex();
    print_edge();
    v1_nei();

    assert(g.RemoveVertex(15) == true);

    printf("v1 has incoming: \n");
    std::vector<WeightedEdge> out = g.GetIncomingEdges(1);
    for (Edge e: out) {
        printf("(%d, %d)", e.GetSource(), e.GetDestination());
    }


    printf("Successful!\n");
}

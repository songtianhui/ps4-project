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
    printf("NR_vertices = %d\n", g.CountVertices());
    assert(g.AddVertex(99999) == false);
    printf("NR_vertices = %d\n", g.CountVertices());
    assert(g.AddVertex(0) == false);
    printf("NR_vertices = %d\n", g.CountVertices());
    assert(g.RemoveVertex(1) == true);
    printf("NR_vertices = %d\n", g.CountVertices());
    assert(g.AddVertex(1) == true);

    printf("NR_vertices = %d\n", g.CountVertices());


    printf("OK!\n");

}
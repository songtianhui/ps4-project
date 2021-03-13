//
// Created by sth on 3/12/21.
//

#include <cassert>
#include <cstdio>
#include <DataStructures/WeightedGraph.h>

using namespace std;

WeightedGraph g;

void printvector(std::vector<WeightedEdge> *wes) {
    for (auto &e : *wes) {
        printf("w(%d, %d) = %d\n", e.GetSource(), e.GetDestination(), e.GetWeight());
    }
}

int main() {
    g.AddVertex(1);
    g.AddVertex(1000);
    g.AddVertex(99999);
    assert(g.AddEdge(1, 1000, 114514) == true);
    assert(g.AddEdge(1000, 99999, 250) == true);
    assert(g.AddEdge(1000, 1, 800) == true);
    assert(g.AddEdge(99999, 1, 99) == true);
    assert(g.AddEdge(1000, 1000, 10) == true);
    assert(g.AddEdge(1, 1000, 1) == false);
    assert(g.AddEdge(1,2, 12) == false);


    std::vector<WeightedEdge> es = g.GetEdges();
    std::vector<WeightedEdge> in = g.GetIncomingEdges(1000);
    std::vector<WeightedEdge> out = g.GetOutgoingEdges(1000);
    std::vector<int> vs = g.GetVertices();

    printf("vs: \n"); for (int i : vs) printf("%d\n", i);
    printf("NR_v = %d\n", g.CountVertices());

    printf("es: \n"); printvector(&es);
    printf("in: \n"); printvector(&in);
    printf("out: \n"); printvector(&out);
    printf("NR_edge = %d\n", g.CountEdges());

    for (auto &e : es) {
        int s = e.GetSource();
        int d = e.GetDestination();
        int w = e.GetWeight();
        assert(g.GetWeight(s,d) == w);
    }

    printf("1000's neibourhood: \n");
    vector<int> nei = g.GetNeighbors(1000);
    for (int i : nei) printf("%d ", i);
    printf("\n");

    printf("remove 1000...\n");

    g.RemoveVertex(1000);
//    g.RemoveEdge(99999, 1);

    std::vector<int> vs2 = g.GetVertices();
    printf("vs2: \n"); for (int i : vs2) printf("%d\n", i);
    printf("NR_v = %d\n", g.CountVertices());

    std::vector<WeightedEdge> es2 = g.GetEdges();
    printf("es2: \n"); printvector(&es2);

    printf("NR_edge = %d\n", g.CountEdges());
    printf("1000's degreee = %d\n", g.GetDegree(1000));
    printf("99999's degree = %d\n", g.GetDegree(99999));
    printf("w(1000, 99999) = %d\n", g.GetWeight(1000, 99999));

    g.RemoveEdge(99999, 1);
    std::vector<WeightedEdge> es3 = g.GetEdges();
    printf("es3: \n"); printvector(&es3);



    printf("OK\n");
    return 0;
}
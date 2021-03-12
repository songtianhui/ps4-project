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
    g.AddEdge(1, 1000, 114514);
    g.AddEdge(1000, 99999, 250);
    assert(g.AddEdge(1,2, 12) == false);
    printf("w(1,1000) = %d\n", g.GetWeight(1,1000));
    printf("w(1000,99999) = %d\n", g.GetWeight(1000,99999));
    printf("OK!\n");

    std::vector<WeightedEdge> es = g.GetEdges();
    std::vector<WeightedEdge> in = g.GetIncomingEdges(1000);
    std::vector<WeightedEdge> out = g.GetOutgoingEdges(1000);

    printvector(&es);
    printvector(&in);
    printvector(&out);

    return 0;
}
//
// Created by sth on 2021/5/15.
//

#include <Algorithms/BiparititeGraphMatching.h>
#include <DataStructures/UndirectedWeightedGraph.h>

UndirectedWeightedGraph<int> g;

void init_g() {
    g.AddVertex(8);
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


//    g.AddEdge(8,0,1);
//    assert(g.AddEdge(1, 1000, 114514) == true);
    assert(g.AddEdge(0, 1000, 100) == true);
//    assert(g.AddEdge(-114514, 0, 100) == true);
//    assert(g.AddEdge(99999, 0, 0) == true);
    assert(g.AddEdge(1000, 99999, 250) == true);
    assert(g.AddEdge(99999, 1, 99) == true);
//    assert(g.AddEdge(1000, 1000, 10) == true);
}

int main() {
    init_g();
    std::unordered_set<int> left;
    std::unordered_set<int> right;
    left.insert(1);
    left.insert(1000);
    right.insert(99999);
    right.insert(0);
    right.insert(-114514);
    try {
        BipariteGraphMatching<UndirectedWeightedGraph<int>> bm(&g, left, right);
        printf("ans = %d\n", bm.SumOfMatches());
        for (int i : g.GetVertices()) {
            if (bm.FindMatchOf(i) != std::nullopt)
                printf("%d : %d\n", i, bm.FindMatchOf(i).value());
        }
    } catch (std::invalid_argument) {
        printf("catch\n");
    }
    return 0;
}

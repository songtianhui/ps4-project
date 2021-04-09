//
// Created by sth on 2021/4/8.
//

#include <Algorithms/DepthFirstSearcher.h>
#include <unordered_set>

template <typename TGraph>
void DepthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start,
                                                  const std::function<void(int)> &action) {
    if(!graph->ContainsVertex(start)) return;

    static std::unordered_set<int> vis;
    action(start);
    vis.insert(start);

    for (int next : graph->GetNeighbors(start)) {
        if (vis.find(next) == vis.end()) {
            DepthFirstSearcher<TGraph>::VisitAllVertices(graph, next, action);
        }
    }
}

template <typename TGraph>
std::optional<int> DepthFirstSearcher<TGraph>::FindFirstVertex(const TGraph *graph, int start,
                                                               const std::function<bool(int)> &predicate) {

    if(!graph->ContainsVertex(start)) return std::nullopt;

    static std::unordered_set<int> vis;
    if (predicate(start)) return start;
    vis.insert(start);

    for (int next : graph->GetNeighbors(start)) {
        if (vis.find(next) == vis.end()) {
            std::optional<int> tmp = DepthFirstSearcher<TGraph>::VisitAllVertices(graph, next, predicate);
            if (tmp != std::nullopt) return tmp;
        }
    }
    return std::nullopt;
}

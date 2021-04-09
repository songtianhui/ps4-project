//
// Created by sth on 2021/4/8.
//

#include <Algorithms/BreadthFirstSearcher.h>
#include <unordered_set>
#include <vector>
#include <queue>

template <typename TGraph>
void BreadthFirstSearcher<TGraph>::VisitAllVertices(const TGraph *graph, int start,
                                                    const std::function<void(int)> &action) {
    if (!graph->ContainsVertex(start)) return;

    std::unordered_set<int> vis;
    std::queue<int> q;

    action(start);
    q.emplace(start);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        vis.emplace(cur);
        for (int next : graph->GetNeighbors(cur)) {
            if (vis.find(next) == vis.end()) {
                action(next);
                q.emplace(next);
            }
        }
    }
}

template <typename TGraph>
std::optional<int> BreadthFirstSearcher<TGraph>::FindFirstVertex(const TGraph *graph, int start,
                                                                 const std::function<bool(int)> &predicate) {
    if (!graph->ContainsVertex(start)) return std::nullopt;

    std::unordered_set<int> vis;
    std::queue<int> q;

    if (predicate(start)) return start;
    q.emplace(start);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        vis.emplace(cur);
        for (int next : graph->GetNeighbors(cur)) {
            if (vis.find(next) == vis.end()) {
                if (predicate(next)) return next;
                q.emplace(next);
            }
        }
    }

    return std::nullopt;
}
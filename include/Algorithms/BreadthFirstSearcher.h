#ifndef BREADTH_FIRST_SEARCHER
#define BREADTH_FIRST_SEARCHER

#include <functional>
#include <optional>
#include <unordered_set>
#include <vector>
#include <queue>
#include <cassert>

template<typename TGraph>
class BreadthFirstSearcher {
public:
    static void VisitAllVertices(const TGraph *graph, int start, const std::function<void(int)> &action) {
        if (!graph->ContainsVertex(start)) return;

        std::unordered_set<int> vis;
        std::queue<int> q;

        action(start);
        vis.emplace(start);
        q.push(start);

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            assert(vis.find(cur) != vis.end());
            for (int next : graph->GetNeighbors(cur)) {
                if (vis.find(next) == vis.end()) {
                    action(next);
                    vis.emplace(next);
                    q.push(next);
                }
            }
        }
    }

    static std::optional<int>
    TryFindFirstVertex(const TGraph *graph, int start, const std::function<bool(int)> &predicate) {
        if (!graph->ContainsVertex(start)) return std::nullopt;

        std::unordered_set<int> vis;
        std::queue<int> q;

        if (predicate(start)) return start;
        vis.emplace(start);
        q.push(start);

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            assert(vis.find(cur) != vis.end());
            for (int next : graph->GetNeighbors(cur)) {
                if (vis.find(next) == vis.end()) {
                    if (predicate(next)) return next;
                    vis.emplace(next);
                    q.push(next);
                }
            }
        }

        return std::nullopt;
    }
};

#endif

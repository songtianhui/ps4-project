#ifndef BREADTH_FIRST_SEARCHER
#define BREADTH_FIRST_SEARCHER

#include <functional>
#include <optional>
#include <unordered_set>
#include <vector>
#include <queue>
#include <DataStructures/UndirectedGraph.h>

template<typename TGraph>
class BreadthFirstSearcher {
public:
    static void VisitAllVertices(const UndirectedGraph *graph, int start, const std::function<void(int)> &action) {
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
                    vis.emplace(next);
                }
            }
        }
    }

    static std::optional<int>
    FindFirstVertex(const TGraph *graph, int start, const std::function<bool(int)> &predicate) {
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
};

#endif

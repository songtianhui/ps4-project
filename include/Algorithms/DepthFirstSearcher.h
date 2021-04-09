#ifndef DEPTH_FIRST_SEARCHER
#define DEPTH_FIRST_SEARCHER

#include <functional>
#include <optional>
#include <unordered_set>

template<typename TGraph>
class DepthFirstSearcher {
public:
    static void VisitAllVertices(const TGraph *graph, int start, const std::function<void(int)> &action) {
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

    static std::optional<int>
    FindFirstVertex(const int *graph, int start, const std::function<bool(int)> &predicate) {
        if(!graph->ContainsVertex(start)) return std::nullopt;

        static std::unordered_set<int> vis;
        if (predicate(start)) return start;
        vis.insert(start);

        for (int next : graph->GetNeighbors(start)) {
            if (vis.find(next) == vis.end()) {
                std::optional<int> tmp = DepthFirstSearcher<TGraph>::FindFirstVertex(graph, next, predicate);
                if (tmp != std::nullopt) return tmp;
            }
        }
        return std::nullopt;
    }
};

#endif

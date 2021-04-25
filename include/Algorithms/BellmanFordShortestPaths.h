//
// Created by sth on 2021/4/25.
//

#ifndef GRAPHLIBRARY_BELLMANFORDSHORTESTPATHS_H
#define GRAPHLIBRARY_BELLMANFORDSHORTESTPATHS_H

#include <Algorithms/ShortestPaths.h>
#include <queue>

template<typename TGraph>
class BellmanFordShortestPaths : public ShortestPaths<TGraph> {
private:
    typedef typename TGraph::value_type TValue;
    std::map<int, std::optional<TValue> > cost;  // src到点的距离
    std::map<int, std::optional<int> >   pre;   // src到点最短路径的该点前一个点

private:
    void Init() {
        cost[this->GetSource()] = TValue();
    }

public:
    BellmanFordShortestPaths() = delete;

    BellmanFordShortestPaths(const TGraph *graph, int source) : ShortestPaths<TGraph>(graph, source) {
//        if (!graph->ContainsVertex(source)) return;
//        Init();
//        std::unordered_set<int> vis;
//        for (int i = 1; i < graph->CountVertices(); ++i) {
//            for (auto &e : graph->GetEdges()) {
//                const int src = e.GetSource();
//                const int dst = e.GetDestination();
//                const TValue w = e.GetWeight();
//                const std::optional<TValue> cur_cost = cost[src];
//                // 检查cur_cost
//                if (cur_cost == std::nullopt) continue;
//                const TValue new_cost = cur_cost.value() + w;
//                if (cost[dst] == std::nullopt || new_cost < cost[dst].value()) {
//                    cost[dst] = new_cost;
//                    pre[dst] = src;
//                }
//            }
//        }

        if (!graph->ContainsVertex(source)) return;
        Init();
        std::unordered_set<int> vis;
        std::priority_queue<std::pair<TValue, int>, std::vector<std::pair<TValue, int> >, std::greater<std::pair<TValue, int>>> pq;
        int src = this->GetSource();
        cost[src] = TValue();
        pre[src] = src;
        pq.emplace(TValue(), src);
        while (!pq.empty()) {
            const auto state = pq.top();
            pq.pop();
            const TValue cur_cost = state.first;
            const int    cur_idx  = state.second;
            if (vis.find(cur_idx) != vis.end()) continue;
            vis.emplace(cur_idx);
            for (const auto &e : graph->GetOutgoingEdges(cur_idx)) {
                assert(cur_idx == e.GetSource());
                const int new_idx  = e.GetDestination();
                assert(graph->ContainsVertex(new_idx));
                const TValue new_cost = cur_cost + e.GetWeight();
                if (cost[new_idx] == std::nullopt || new_cost < cost[new_idx]) {
                    pq.push({new_cost, new_idx});
                    cost[new_idx] = new_cost;
                    pre[new_idx]  = cur_idx;
                }
            }
        }
    }

    virtual ~BellmanFordShortestPaths() {}

public:
    bool HasPathTo(int destination) const override {
        auto it = cost.find(destination);
        if (it == cost.end()) return false;
        if (it->second == std::nullopt) return false;
        return true;
    }

    std::optional<TValue> TryGetDistanceTo(int destination) const override {
        auto it = cost.find(destination);
        if (it == cost.end()) return std::nullopt;
        return (it->second.value());
    }

    std::optional<std::vector<int> > TryGetShortestPathTo(int destination) const override {
        auto it = cost.find(destination);
        int src = ShortestPaths<TGraph>::GetSource();
        if (it == cost.end() || it->second == std::nullopt) return std::nullopt;
        std::vector<int> ret;
        int cur = destination;
        while (cur != src){
            ret.push_back(cur);
            auto it = pre.find(cur);
            assert(it != pre.end() && it->second != std::nullopt);
            cur = it->second.value();
        }
        ret.push_back(src);
        return ret;
    }


};

#endif //GRAPHLIBRARY_BELLMANFORDSHORTESTPATHS_H

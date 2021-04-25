//
// Created by sth on 2021/4/25.
//

#ifndef GRAPHLIBRARY_BELLMANFORDSHORTESTPATHS_H
#define GRAPHLIBRARY_BELLMANFORDSHORTESTPATHS_H

#include <Algorithms/ShortestPaths.h>

template<typename TGraph>
class BellmanFordShortestPaths : public ShortestPaths<TGraph> {
private:
    typedef typename TGraph::value_type TValue;
    std::map<int, std::optional<TValue> > cost;  // src到点的距离
    std::map<int, std::optional<int> >   pre;   // src到点最短路径的该点前一个点

private:
    void init() {
        cost[this->GetSource()] = TValue();
    }

public:
    BellmanFordShortestPaths() = delete;

    BellmanFordShortestPaths(const TGraph *graph, int source) : ShortestPaths<TGraph>(graph, source) {
        if (!graph->ContainsVertex(source)) return;
        init();
        std::unordered_set<int> vis;
        for (int i = 1; i < graph->CountVertices(); ++i) {
            for (int v : graph->GetVertices()) {
                for (auto &e : graph->GetOutgoingEdges(v)) {
                    const int src = e.GetSource();
                    assert(src == v);
                    const int dst = e.GetDestination();
                    const TValue w = e.GetWeight();
                    const std::optional<TValue> cur_cost = cost[src];
                    // 检查cur_cost
                    if (cur_cost == std::nullopt) continue;
                    const TValue new_cost = cur_cost.value() + w;
                    if (cost[dst] == std::nullopt || new_cost < cost[dst].value()) {
                        cost[dst] = new_cost;
                        pre[dst] = src;
                    }
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
        return (it->second);
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

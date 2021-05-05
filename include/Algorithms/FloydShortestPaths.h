//
// Created by sth on 2021/5/4.
//

#ifndef GRAPHLIBRARY_FLOYDSHORTESTPATHS_H
#define GRAPHLIBRARY_FLOYDSHORTESTPATHS_H

#include <Algorithms/MultiSourceShortestPaths.h>
#include <map>
#include <unordered_map>

template <typename TGraph>
class FloydShortestPaths : public MultiSourceShortestPaths<TGraph> {
private:
    typedef typename TGraph::value_type TValue;
    std::unordered_map<std::pair<int, int>, std::optional<TValue> > cost;
    std::unordered_map<std::pair<int, int>, std::optional<int> > pre;
private:
    void init(TGraph *g) {
        for (int i : g->GetVeertices()) {
            for (int j : g->GetVertices()) {
                if (g->ContainsEdge(i,j)) {
                    cost[std::make_pair(i,j)] = g->GetWeight(i,j);
                    pre[std::make_pair(i,j)] = i;
                } else if (i == j) {
                    cost[std::make_pair(i,j)] = TValue();
                    pre[std::make_pair(i,j)] = i;
                } else {
                    cost[std::make_pair(i,j)] = std::nullopt;
                    pre[std::make_pair(i,j)] = std::nullopt;
                }
            }
        }
    }

public:
    FloydShortestPaths() = delete;

    FloydShortestPaths(const TGraph *graph) : MultiSourceShortestPaths<TGraph>(graph) {
        init(graph);
        const std::vector<int> vertices = graph->GetVertices();
        for (int k : vertices) {
            for (int i : vertices) {
                for (int j : vertices) {
                    std::optional<TValue> cur_cost   = cost.find(std::make_pair(i,j));
                    std::optional<TValue> new_first  = cost.find(std::make_pair(i,k));
                    std::optional<TValue> new_second = cost.find(std::make_pair(k,j));
                    std::optional<TValue> new_cost;
                    if (new_first == std::nullopt || new_second == std::nullopt) new_cost = std::nullopt;
                    else new_cost = new_first + new_second;

                    if (cur_cost == std::nullopt || (new_cost != std::nullopt && cur_cost.value() > new_cost.value())) {
                        cost[std::make_pair(i,j)] = new_cost;
                        pre[std::make_pair(i,j)] = pre[std::make_pair(k,j)];
                    }
                }
            }
        }

    }

    virtual ~FloydShortestPaths() {}

public:
    bool HasPathTo(int source, int destination) const override {
        auto it = cost.find(std::make_pair(source, destination));
        if (it == cost.end()) return false;
        if (it->second == std::nullopt) return false;
        return true;
    }

    std::optional<TValue> TryGetDistanceTo(int source, int destination) const override {
        auto it = cost.find(std::make_pair(source, destination));
        if (it == cost.end()) return std::nullopt;
        if (it->second == std::nullopt) return std::nullopt;
        return (it->second.value());

    }

    std::optional<std::vector<int>> TryGetShortestPathTo(int source, int destination) const override {
        auto it = cost.find(std::make_pair(source, destination));
        if (it == cost.end() || it->second == std::nullopt) return std::nullopt;
        std::vector<int> ret;
        int cur = destination;
        while (cur != source) {
            ret.push_back(cur);
            auto it = pre.find(std::make_pair(source, cur));
            assert(it != pre.end() && it->second != std::nullopt);
            cur = it->second.value();
        }
        ret.push_back(source);
        return ret;
    }
};

#endif //GRAPHLIBRARY_FLOYDSHORTESTPATHS_H

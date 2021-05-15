#ifndef GRAPHLIBRARY_BIPARTITEGRAPHMATCHING_H
#define GRAPHLIBRARY_BIPARTITEGRAPHMATCHING_H
#include <unordered_set>
#include <optional>
#include <unordered_map>

template<typename TGraph>
class BipariteGraphMatching {
private:
    const TGraph *graph;
    std::unordered_set<int> used;
    std::unordered_map<int, int> belong;
    int total;

private:
    bool find(int x) {
        for (auto &y : graph->GetNeighbors()) {
            if (used.find(y) == used.end()) {
                used.insert(y);
                if (belong.find(y) == belong.end() || find(belong[y])) {
                    belong[y] = x;
                    belong[x] = y;
                    return true;
                }
            }
        }
        return false;
    }
public:
    BipariteGraphMatching(const TGraph* g, std::unordered_set<int> left, std::unordered_set<int> right) {
        graph = g;
        for (int i : left) {
            used.clear();
            if (find(i)) total++;
        }
    }

    int SumOfMatches() const { return total; }

    std::optional<int> FindMatchOf(int idx) {
        auto it = belong.find(idx);
        if (it == belong.end()) return std::nullopt;
        if (!graph->ContainsVertex(idx)) return std::nullopt;
        return it->second;
    }
};

#endif //GRAPHLIBRARY_BIPARTITEGRAPHMATCHING_H

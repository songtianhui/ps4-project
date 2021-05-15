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
    std::unordered_set<int> l;
    std::unordered_set<int> r;

private:
    bool find(int x) {
        for (auto &y : graph->GetNeighbors(x)) {
            if (l.find(y) == l.end() && used.find(y) == used.end()) {
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
        l = left;
        r = right;
        belong.clear();
        total = 0;

        for (int i : left) {
            if (right.find(i) != right.end()) {
                throw std::invalid_argument("shared vertex");
            }
        }
        for (int i : left) {
            if (!g->ContainsVertex(i)) {
                throw std::invalid_argument("vertex not in g");
            }
        }
        for (int i : right) {
            if (!g->ContainsVertex(i)) {
                throw std::invalid_argument("vertex not in g");
            }
        }
        for (int i : left) {
            for (int j : g->GetNeighbors(i)) {
                if (right.find(j) == right.end()) {
                    throw std::invalid_argument("neighbors of left not in right");
                }
            }
        }
        for (int i : right) {
            for (int j : g->GetNeighbors(i)) {
                if (left.find(j) == left.end()) {
                    throw std::invalid_argument("neighbors of right not in left");
                }
            }
        }
        for (int i : left) {
            used.clear();
            if (find(i)) total++;
        }
    }

    int SumOfMatches() const { return total; }

    std::optional<int> FindMatchOf(int idx) const {
        auto it = belong.find(idx);
        if (it == belong.end()) return std::nullopt;
        if (!graph->ContainsVertex(idx)) return std::nullopt;
        return it->second;
    }
};

#endif //GRAPHLIBRARY_BIPARTITEGRAPHMATCHING_H

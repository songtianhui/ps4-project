//
// Created by sth on 3/27/21.
//

#ifndef GRAPHLIBRARY_GENERIC_H
#define GRAPHLIBRARY_GENERIC_H

#include <map>
#include <unordered_map>
#include <cassert>
#include <vector>
#define MAXV 1005

template <typename TEdge>
class Generic {
protected:
    std::map<std::pair<int, int>, int> exist;           // 邻接表, i不在表示没有点i，edges[i]为空表示有点i
    std::unordered_map<int, std::vector<TEdge> > edges; // 记录 edges[.first.first][.second] = .first.second, 找不到或.second = -1说明不存在

    int NR_vertices;
    int NR_edges;

public:
    Generic() {
        exist.clear();
        edges.clear();
        NR_vertices = NR_edges = 0;
    }

    virtual ~Generic() {}

protected:
    bool InsertEdge(TEdge e) {
        const int src = e.GetSource();
        const int dst = e.GetDestination();
        if (!ContainsVertex(src) || !ContainsVertex(dst) || ContainsEdge(src,dst)) return false;

        edges[src].push_back(e);
        exist[std::make_pair(src, dst)] = edges[src].size() - 1;    // 该边在edges[src]中的id
        assert(exist[std::make_pair(src,dst)] >= 0);
        NR_edges++;
        return true;
    }

public:
    bool AddVertex(int vertex) {
        if (ContainsVertex(vertex)) return false;
        edges[vertex].clear();
        NR_vertices++;
        return true;
    }

    bool RemoveVertex(int vertex) {
        auto it = edges.find(vertex);
        if (it == edges.end()) return false;
        it->second.clear();
        edges.erase(it);
        NR_vertices--;
        return true;
    }

    virtual bool RemoveEdge(int vertex1, int vertex2) {
        if (!ContainsVertex(vertex1) || !ContainsVertex(vertex2) || !ContainsEdge(vertex1, vertex2)) return false;

        auto it = exist.find(std::make_pair(vertex1, vertex2));
        exist.erase(it);
        NR_edges--;
        return true;
    }

public:
    int CountVertices() const {
        return NR_vertices;
    }

    virtual int CountEdges() const {
        return NR_edges;
    }

    bool ContainsVertex(int vertex) const {
        if (edges.find(vertex) == edges.end()) return false;
        return true;
    }

    virtual bool ContainsEdge(int vertex1, int vertex2) const {
        auto it = exist.find(std::make_pair(vertex1, vertex2));
        if (it == exist.end() || it->second < 0) return false;
        return true;
    }

    std::vector<int> GetVertices() const {
        std::vector<int> allvertices;
        for (auto it = edges.begin(); it != edges.end(); ++it) {
            int id = it->first;
            allvertices.push_back(id);
        }
        return allvertices;
    }

    virtual std::vector<TEdge> GetEdges() const {
        std::vector<TEdge> alledges;

        for (auto it = exist.begin(); it != exist.end(); ++it) {
            const int src = it->first.first;
            const int dst = it->first.second;
            const int idx = it->second;
            assert(idx >= 0);

            auto it2 = edges.find(src);
            assert(it2 != edges.end());
            alledges.push_back((it2->second)[idx]);
        }

        return alledges;
    }

    std::vector<TEdge> GetIncomingEdges(int vertex) const {
        std::vector<TEdge> inedges;
        for (auto it = exist.begin(); it != exist.end(); ++it) {
            const int src = it->first.first;
            const int dst = it->first.second;
            const int idx = it->second;
            assert(idx >= 0);

            auto it2 = edges.find(src);
            assert(it2 != edges.end());
            if (dst == vertex) inedges.push_back((it2->second)[idx]);
        }
        return inedges;
    }

    std::vector<TEdge> GetOutgoingEdges(int vertex) const {
        std::vector<TEdge> outedges;
        for (auto it = exist.begin(); it != exist.end(); ++it) {
            const int src = it->first.first;
            const int dst = it->first.second;
            const int idx = it->second;
            assert(idx >= 0);

            auto it2 = edges.find(src);
            assert(it2 != edges.end());
            if (src == vertex) outedges.push_back((it2->second)[idx]);
        }
        return outedges;
    }

    virtual int GetDegree(int vertex) const {
        int ans = 0;
        auto it = edges.find(vertex);
        if (it == edges.end()) return 0;
        for (TEdge e : it->second) {
            int src = e.GetSource();
            int dst = e.GetDestination();
            if (exist.find(std::make_pair(src, dst)) != exist.end()) {
                ans ++;
            }
        }
        return ans;
    }

    std::vector<int> GetNeighbors(int vertex) const {
        std::vector<int> nei;
        auto it = edges.find(vertex);
        if (it == edges.end()) return nei;
        for (TEdge e : it->second) {
            const int src = e.GetSource();
            const int dst = e.GetDestination();
            if (exist.find(std::make_pair(src, dst)) != exist.end()) {
                nei.push_back(dst);
            }
        }
        return nei;
    }
};


#endif //GRAPHLIBRARY_GENERIC_H

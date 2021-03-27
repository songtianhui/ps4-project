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
private:
    std::unordered_map<int, std::vector<TEdge> > edges;    //邻接表, i不在表示没有点i，edges[i]为空表示有点i
    std::map<std::pair<int, int>, bool> exist;
    int NR_vertices;
    int NR_edges;

public:
    Generic() {
        edges.clear();
        exist.clear();
        NR_vertices = NR_edges = 0;
    }

    virtual ~Generic();

protected:
    bool InsertEdge(TEdge e) {
        const int src = e.GetSource();
        const int dst = e.GetDestination();
        if (edges.find(src) == edges.end() || edges.find(dst) == edges.end() || exist.find(std::make_pair(src, dst)) != exist.end()) return false;

        edges[src].push_back(e);
        exist[std::make_pair(src, dst)] = true;
        NR_edges++;
        return true;
    }

public:
    bool AddVertex(int vertex) {
        if (edges.find(vertex) != edges.end()) return false;
        edges[vertex].clear();
        NR_vertices++;
        return true;
    }

    bool RemoveVertex(int vertex) {
        auto it = edges.find(vertex);
        if (it == edges.end()) return false;
        edges.erase(it);
        NR_vertices--;
        return true;
    }

    bool RemoveEdge(int vertex1, int vertex2) {
        if (edges.find(vertex1) == edges.end() || edges.find(vertex2) == edges.end() || exist.find(std::make_pair(vertex1, vertex2)) == exist.end()) return false;

        auto it = exist.find(std::make_pair(vertex1, vertex2));
        edges.erase(it);
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

    bool ContainsEdge(int vertex1, int vertex2) const {
        auto it = exist.find({vertex1, vertex2});
        if (it == exist.end()) return false;
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

    std::vector<std::pair<int, int> > ObtainEdges() const {
        std::vector<std::pair<int, int> > alledges;
        for (auto it = exist.begin(); it != exist.end(); ++it) {
            alledges.push_back(it->first);
        }
        return alledges;
    }

    std::vector<std::pair<int, int> > ObtainIncomingEdges(int vertex) const {
        std::vector<std::pair<int, int> > inedges;
        for (auto it = exist.begin(); it != exist.end(); ++it) {
            if (it->first.second == vertex) inedges.push_back(it->first);
        }
        return inedges;
    }

    std::vector<std::pair<int, int> > ObtainOutgoingEdges(int vertex) const {
        std::vector<std::pair<int, int> > outedges;
        for (auto it = exist.begin(); it != exist.end(); ++it) {
            if (it->first.first == vertex) outedges.push_back(it->first);
        }
        return outedges;
    }

    int GetDegree(int vertex) const {
        int ans = 0;
        auto it = edges.find(vertex);
        if (it == edges.end()) return 0;
        for (TEdge &e : it->second) {
            const int src = e.GetSource;
            const int dst = e.GetDestination;
            if (exist.find(std::make_pair(src, dst)) != exist.end()) {
                ans ++;
            }
        }
        return ans;
    }

    std::vector<int> GetNeighbors(int vertex) const {
        std::vector<int> nei;
        auto it = edges.find(vertex);
        for (TEdge &e : it->second) {
            const int src = e.GetSource;
            const int dst = e.GetDestination;
            if (exist.find(std::make_pair(src, dst)) != exist.end()) {
                nei.push_back(dst);
            }
        }
        return nei;
    }
};


#endif //GRAPHLIBRARY_GENERIC_H

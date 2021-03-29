//
// Created by sth on 3/28/21.
//

#ifndef GRAPHLIBRARY_UNDIRECTEDGENERIC_H
#define GRAPHLIBRARY_UNDIRECTEDGENERIC_H

#include <DataStructures/Generic.h>

template <typename TEdge>
class UndirectedGeneric : public Generic<TEdge> {
public:
    UndirectedGeneric();
    ~UndirectedGeneric();

public:
    bool InsertEdge(TEdge e) override {
        const int src = e.GetSource();
        const int dst = e.GetDestination();
        if (!this->ContainsVertex(src) || !this->ContainsVertex(dst) || (ContainsEdge(src,dst) && ContainsEdge(dst,src))) return false;

        this->edges[src].push_back(e);
        this->exist[std::make_pair(src, dst)] = this->edges[src].size() - 1;    // 该边在edges[src]中的id
        assert(this->exist[std::make_pair(src,dst)] >= 0);
        this->NR_edges++;
        return true;
    }


    bool RemoveEdge(int vertex1, int vertex2) override {
        bool succ1 = Generic<TEdge>::RemoveEdge(vertex1, vertex2);
        bool succ2 = true;

        if (vertex1 != vertex2) {
            succ2 = RemoveEdge(vertex2, vertex1);
            this->NR_edges++;
        }

        return succ1 && succ2;
    }

    bool ContainsEdge(int vertex1, int vertex2) const override {
        return Generic<TEdge>::ContainsEdge(vertex1, vertex2) || Generic<TEdge>::ContainsEdge(vertex2, vertex1);
    }

    std::vector<TEdge> GetEdges() const override {
        std::vector<TEdge> alledges;
        std::vector<TEdge> es = Generic<TEdge>::GetEdges();
        std::map<std::pair<int,int>, bool> vis;
        for (TEdge &e : es) {
            const int src = e.GetSource();
            const int dst = e.GetDestination();
            if (vis.find(std::make_pair(src, dst)) == vis.end() && vis.find(std::make_pair(dst, src)) == vis.end()) {
                alledges.push_back(e);
                vis[std::make_pair(src, dst)] = true;
            }
        }
        return alledges;
    }

    int GetDegree(int vertex) const override {
        int res = Generic<TEdge>::GetDegree(vertex);
        if (ContainsEdge(vertex, vertex)) res++;
        return res;
    }
};

#endif //GRAPHLIBRARY_UNDIRECTEDGENERIC_H

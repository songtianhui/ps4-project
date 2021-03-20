//
// Created by sth on 3/20/21.
//

#ifndef GRAPHLIBRARY_UNDIRECTEDGRAPH_H
#define GRAPHLIBRARY_UNDIRECTEDGRAPH_H

#include <DataStructures/Graph.h>

class UndirectedGraph {
private:
    bool used[MAXV + 1];
    int key[MAXV + 1];     //映射值对应的原值，0表示没有用
    int map[MAXV + 1][MAXV + 1];  //邻接矩阵, [from][to]
    int NR_vertices;
    int NR_edges;

private:
    std::unordered_map<int, int> mp;  //把编号离散到1~1000

private:
    int mapping(int vertex);

public:
    UndirectedGraph();

    ~UndirectedGraph();

public:
    bool AddVertex(int vertex);

    bool RemoveVertex(int vertex);

    virtual bool AddEdge(int vertex1, int vertex2);

    virtual bool RemoveEdge(int vertex1, int vertex2);

public:
    int CountVertices() const;

    virtual int CountEdges() const;

    bool ContainsVertex(int vertex) const;

    bool ContainsEdge(int vertex1, int vertex2) const;

    std::vector<int> GetVertices() const;

    std::vector<Edge> GetEdges() const;

    std::vector<Edge> GetIncomingEdges(int vertex) const;

    std::vector<Edge> GetOutgoingEdges(int vertex) const;

    int GetDegree(int vertex) const;

    std::vector<int> GetNeighbors(int vertex) const;

public:

    int Getmap(int vertex) const;
};

#endif //GRAPHLIBRARY_UNDIRECTEDGRAPH_H

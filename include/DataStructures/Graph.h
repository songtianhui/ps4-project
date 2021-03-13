#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <cstring>
#include <DataStructures/Edge.h>

#define MAXV 1005

#define RED "\33[1;31m"
#define ORI "\33[0m"
#define Assert(_con, _fmt, ...) \
 do{\
     if(!(_con)){\
         fprintf(stderr,RED "Assertion failed:\nLine: %d\n" _fmt, __LINE__ ,##__VA_ARGS__);\
         assert(0);\
     }\
 }while(0)

class Graph {
private:
    int exist[MAXV + 1];     //映射值对应的原值，0表示没有用
    int map[MAXV + 1][MAXV + 1];  //邻接矩阵, [from][to]
    //std::vector<int> edges[MAXV]; //邻接链表
    int NR_vertices;
    int NR_edges;
protected:
    std::unordered_map<int, int> mp;  //把编号离散到1~1000

private:
    int mapping(int vertex);
    //void update_list();

public:
    Graph();

    ~Graph();

public:
    bool AddVertex(int vertex);

    bool RemoveVertex(int vertex);

    bool AddEdge(int vertex1, int vertex2);

    bool RemoveEdge(int vertex1, int vertex2);

public:
    int CountVertices() const;

    int CountEdges() const;

    bool ContainsVertex(int vertex) const;

    bool ContainsEdge(int vertex1, int vertex2) const;

    std::vector<int> GetVertices() const;

    std::vector<Edge> GetEdges() const;

    std::vector<Edge> GetIncomingEdges(int vertex) const;

    std::vector<Edge> GetOutgoingEdges(int vertex) const;

    int GetDegree(int vertex) const;

    std::vector<int> GetNeighbors(int vertex) const;
};

#endif

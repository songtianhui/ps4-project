#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <cstring>
#include <DataStructures/Edge.h>
#define MAXV 10005

class Graph {
 private:
  bool exist[MAXV];
  int map[MAXV][MAXV];  //邻接矩阵, [from][to]
  std::vector<int> edges[MAXV];
  int NR_vertices;
  int NR_edges;

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

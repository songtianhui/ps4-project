#include <DataStructures/Graph.h>
#include <cstdio>

Graph::Graph() {
  memset(exist, false, sizeof(exist));
  memset(map, 0, sizeof(map));
  for (int i=0; i<MAXV; ++i) edges[i].clear();
  NR_edges = NR_vertices = 0;
}

Graph::~Graph() {
}

bool Graph::AddVertex(int vertex) {
  if (!exist[vertex]) {
    exist[vertex] = true;
    NR_vertices++;
    edges[vertex].clear();
    return true;
  }
  return false;
}

bool Graph::RemoveVertex(int vertex) {
  if (exist[vertex]) {
    exist[vertex] = false;
    NR_vertices--;
    edges[vertex].clear();
    for (int i = 0; i < MAXV; ++i) {
      if(map[vertex][i]) map[vertex][i] = 0;
      if(map[i][vertex]) map[i][vertex] = 0;
    }
    return true;
  }
  return false;
}

bool Graph::AddEdge(int vertex1, int vertex2) {
  if (!exist[vertex1] || !exist[vertex2] || map[vertex1][vertex2]) {
    return false;
  }
  map[vertex1][vertex2] = 1;
  edges[vertex1].push_back(vertex2);
  NR_edges++;
  return true;
}

bool Graph::RemoveEdge(int vertex1, int vertex2) {
  if (!exist[vertex1] || !exist[vertex2] || !map[vertex1][vertex2]){
    return false;
  }
  map[vertex1][vertex2] = 0;
  for (auto it=edges[vertex1].begin(); it != edges[vertex1].end(); ) {
    if(*it == vertex2) {
      it = edges[vertex1].erase(it);
    } else {
      ++it;
    }
  }
  NR_edges--;
  return true;
}

int Graph::CountVertices() const {
  return NR_vertices;
}

int Graph::CountEdges() const {
  return NR_edges;
}

bool Graph::ContainsVertex(int vertex) const {
  if (exist[vertex]) return true;
  return false;
}

bool Graph::ContainsEdge(int vertex1, int vertex2) const {
  if (exist[vertex1] && exist[vertex2] && map[vertex1][vertex2]) {
    return true;
  }
  return false;
}

std::vector<int> Graph::GetVertices() const {
  std::vector<int> allvertices;
  for (int i=0; i<MAXV; ++i) {
    if (exist[i]) allvertices.push_back(i);
  }
  return allvertices;
}

std::vector<Edge> Graph::GetEdges() const {
  std::vector<Edge> alledges;
  for (int i=0; i<MAXV; ++i) {
    for (int j=0; j<MAXV; ++j) {
      if(map[i][j]) {
        alledges.push_back(Edge(i, j));
        printf("Have edge (%d, %d)", i,j);
      }
    }
  }
  return alledges;
}

std::vector<Edge> Graph::GetIncomingEdges(int vertex) const {
  std::vector<Edge> ret;
  for (int i=0; i<MAXV; ++i) {
    if (map[i][vertex]) {
      ret.push_back(Edge(i,vertex));
    }
  }
  return ret;
}

std::vector<Edge> Graph::GetOutgoingEdges(int vertex) const {
  std::vector<Edge> ret;
  for (int next: edges[vertex]) {
    ret.push_back(Edge(vertex, next));
  }
  return ret;
}

int Graph::GetDegree(int vertex) const {
  if (!exist[vertex]) return 0;
  return edges[vertex].size();
}

std::vector<int> Graph::GetNeighbors(int vertex) const {
  return edges[vertex];
}


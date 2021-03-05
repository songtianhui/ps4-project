#include <DataStructures/Graph.h>

Graph::Graph() {
  for (int i=0; i<MAXV; ++i) {
    memset(edges, 0, sizeof(edges));
    memset(exist, false, sizeof(exist));
    Edges.clear();
    NR_edges = NR_vertices = 0;
  }
}

Graph::~Graph() {

}

bool Graph::AddVertex(int vertex) {
  if (!exist[vertex]) {
    exist[vertex] = true;
    degree[vertex] = 0;
    NR_vertices++;
    return true;
  }
  return false;
}

bool Graph::RemoveVertex(int vertex) {
  if (exist[vertex]) {
    exist[vertex] = false;
    for (int i = 0; i < MAXV; ++i) {
      if(!edges[vertex][i]) edges[vertex][i] = 0;
      if(!edges[i][vertex]) edges[i][vertex] = 0;
    }
    NR_vertices--;
    return true;
  }
  return false;
}

bool Graph::AddEdge(int vertex1, int vertex2) {
  if (!exist[vertex1] || !exist[vertex2] || edges[vertex1][vertex2]) {
    return false;
  }
  edges[vertex1][vertex2] = 1;
  Edges.push_back(Edge(vertex1,vertex2));
  degree[vertex1]++;
  NR_edges++;
  return true;
}

bool Graph::RemoveEdge(int vertex1, int vertex2) {
  if (!exist[vertex1] || !exist[vertex2] || !edges[vertex1][vertex2]){
    return false;
  }
  edges[vertex1][vertex2] = 0;
  degree[vertex1]--;
  //Edges的remove开销有点大，可以先用edges[v1][v2]判断是否存在
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
  if (exist[vertex1] && exist[vertex2] && edges[vertex1][vertex2]) {
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
  for (Edge e: Edges) {
    int src = e.GetSource();
    int dst = e.GetDestination();
    if (edges[src][dst]) {
      alledges.push_back(e);
    }
  }
  return alledges;
}

std::vector<Edge> Graph::GetIncomingEdges(int vertex) const {
  std::vector<Edge> ret;
  for (int i=0; i<MAXV; ++i) {
    if (edges[i][vertex]) {
      ret.push_back(Edge(i,vertex));
    }
  }
  return ret;
}

std::vector<Edge> Graph::GetOutgoingEdges(int vertex) const {
  std::vector<Edge> ret;
  for (int i=0;i<MAXV; ++i) {
    if (edges[vertex][i]) {
      ret.push_back(Edge(vertex,i));
    }
  }
  return ret;
}

int Graph::GetDegree(int vertex) const {
  if (!exist[vertex]) return 0;
  return degree[vertex];
}

std::vector<int> Graph::GetNeighbors(int vertex) const {
  std::vector<int> neighbours;
  for (int i=0; i<MAXV; ++i) {
    if (exist[vertex] && exist[i] && edges[vertex][i]) {
      neighbours.push_back(i);
    }
  }
  return neighbours;
}


#include <cassert>
#include <cstdio>
#include <DataStructures/Graph.h>
using namespace std;

int main() {
  Graph g;

  assert(g.GetDegree(2) == 0);
  assert(g.CountVertices() == 0);
  assert(g.CountEdges() == 0);
  assert(g.GetIncomingEdges(3).size() == 0);
  assert(g.RemoveEdge(1,2) == false);
  assert(g.ContainsEdge(5,6) == false);
  assert(g.ContainsVertex(2) == false);

  assert(g.AddVertex(1) == true);
  assert(g.GetNeighbors(1).size() == 0);
  assert(g.ContainsVertex(1) == true);
  assert(g.CountVertices() == 1);
  assert(g.CountEdges() == 0);

  assert(g.AddVertex(2) == true);
  assert(g.AddVertex(3) == true);
  assert(g.AddVertex(3) == false);
  assert(g.AddVertex(4) == true);
  assert(g.ContainsVertex(4) == true);
  assert(g.RemoveVertex(4) == true);
  assert(g.ContainsVertex(4) == false);
  assert(g.RemoveVertex(5) == false);

  assert(g.AddEdge(1, 2) == true);
  assert(g.AddEdge(1, 3) == true);
  assert(g.AddEdge(2, 5) == false);
  assert(g.ContainsEdge(1, 2) == true);
  assert(g.ContainsEdge(2, 5) == false);

  assert(g.GetDegree(1) == 2);
  assert(g.GetIncomingEdges(1).empty());
  assert(g.GetOutgoingEdges(1).size() == 2);
  assert(g.GetNeighbors(1).size() == 2);
  assert(g.GetNeighbors(2).empty());

  printf("Successful!\n");
}

//
// Created by sth on 3/20/21.
//

#include <DataStructures/UndirectedGraph.h>
//
//int UndirectedGraph::mapping(int vertex) {
//    for (int i = 1; i <= 1001; ++i) {   //1~1001是有效映射值
//        if (!used[i]) {  //该映射值还没有用
//            used[i] = true;
//            key[i] = vertex;
//            return i;
//        }
//    }
//    return 0;
//}
//
//int UndirectedGraph::Getmap(int vertex) const {
//    auto it = mp.find(vertex);
//    if (it != mp.end()) return it->second;
//    return 0;
//}
//
//UndirectedGraph::UndirectedGraph() {
//    memset(used, false, sizeof used);
//    memset(key, 0, sizeof(key));
//    memset(map, 0, sizeof(map));
//    NR_edges = NR_vertices = 0;
//
//    mp.clear();
//}
//
//UndirectedGraph::~UndirectedGraph() {
//}
//
//bool UndirectedGraph::AddVertex(int vertex) {
//    auto it = mp.find(vertex);
//    if (it != mp.end()) {  //存在该点
//        return false;
//    }
//    mp[vertex] = mapping(vertex);
//    NR_vertices++;
//    return true;
//}
//
//bool UndirectedGraph::RemoveVertex(int vertex) {
//    auto it = mp.find(vertex);
//    if (it == mp.end()) return false;
//
//    vertex = it->second;
//    mp.erase(it);       //映射值取消
//    used[vertex] = false;
//
//    NR_vertices--;
//    for (int i = 1; i < MAXV; ++i) {
//        if (map[vertex][i]) {
//            map[vertex][i] = 0;
//            NR_edges--;
//        }
//        if (map[i][vertex]) {
//            map[i][vertex] = 0;
//        }
//    }
//    return true;
//}
//
//bool UndirectedGraph::AddEdge(int vertex1, int vertex2) {
//    auto it1 = mp.find(vertex1);
//    auto it2 = mp.find(vertex2);
//    if (it1 == mp.end() || it2 == mp.end()) {   //有点不存在
//        return false;
//    }
//    vertex1 = it1->second;
//    vertex2 = it2->second;
//
//    if (map[vertex1][vertex2] == 1 || map[vertex2][vertex1]) return false;   //边存在
//
//    map[vertex1][vertex2] = 1;
//    map[vertex2][vertex1] = 1;
//    NR_edges++;
//
//    return true;
//}
//
//bool UndirectedGraph::RemoveEdge(int vertex1, int vertex2) {
//    auto it1 = mp.find(vertex1);
//    auto it2 = mp.find(vertex2);
//    if (it1 == mp.end() || it2 == mp.end()) {
//        return false;
//    }
//    vertex1 = it1->second;
//    vertex2 = it2->second;
//
//    if (map[vertex1][vertex2] == 0 || map[vertex2][vertex1] == 0) return false;   //边不存在
//
//    map[vertex1][vertex2] = 0;
//    map[vertex2][vertex1] = 0;
//    NR_edges--;
//
//    return true;
//}
//
//int UndirectedGraph::CountVertices() const {
//    assert(NR_vertices == mp.size());
//    return NR_vertices;
//}
//
//int UndirectedGraph::CountEdges() const {
//    return NR_edges;
//}
//
//bool UndirectedGraph::ContainsVertex(int vertex) const {
//    auto it = mp.find(vertex);
//    if (it != mp.end()) return true;
//    return false;
//}
//
//bool UndirectedGraph::ContainsEdge(int vertex1, int vertex2) const {
//    auto it1 = mp.find(vertex1);
//    auto it2 = mp.find(vertex2);
//    if (it1 != mp.end() && it2 != mp.end() && map[it1->second][it2->second]) {
//        return true;
//    }
//    return false;
//}
//
//std::vector<int> UndirectedGraph::GetVertices() const {
//    std::vector<int> allvertices;
//    for (auto it = mp.begin(); it != mp.end(); ++it) {
//        allvertices.push_back(it->first);
//    }
//    return allvertices;
//}
//
//std::vector<Edge> UndirectedGraph::GetEdges() const {
//    std::vector<Edge> alledges;
//    for (int i = 1; i < MAXV; ++i) {
//        for (int j = 1; j <= i; ++j) {
//            if (map[i][j]) {
//                alledges.emplace_back(Edge(key[i], key[j]));
//            }
//        }
//    }
//    return alledges;
//}
//
//std::vector<Edge> UndirectedGraph::GetIncomingEdges(int vertex) const {
//    std::vector<Edge> ret;
//    auto it = mp.find(vertex);
//    if (it == mp.end()) return ret;
//    vertex = it->second;
//
//    for (int i = 1; i < MAXV; ++i) {
//        if (map[i][vertex]) {
//            ret.emplace_back(Edge(key[i], it->first));
//        }
//    }
//    return ret;
//}
//
//std::vector<Edge> UndirectedGraph::GetOutgoingEdges(int vertex) const {
//    std::vector<Edge> ret;
//    auto it = mp.find(vertex);
//    if (it == mp.end()) return ret;
//    vertex = it->second;
//
//    for (int i = 1; i < MAXV; ++i) {
//        if (map[vertex][i]) {
//            ret.emplace_back(Edge(it->first, key[i]));
//        }
//    }
//    return ret;
//}
//
//int UndirectedGraph::GetDegree(int vertex) const {
//    auto it = mp.find(vertex);
//    if (it == mp.end()) return 0;
//    vertex = it->second;
//
//    int ans = 0;
//    for (int i = 1; i < MAXV; ++i) {
//        if (map[vertex][i]) {
//            ans++;
//            if (vertex == i) ans++;
//        }
//    }
//    return ans;
//}
//
//std::vector<int> UndirectedGraph::GetNeighbors(int vertex) const {
//    std::vector<int> nei;
//    auto it = mp.find(vertex);
//    if (it == mp.end()) return nei;
//    vertex = it->second;
//
//    for (int i = 1; i < MAXV; ++i) {
//        if (map[vertex][i]) nei.push_back(key[i]);
//    }
//
//    return nei;
//}

#include <DataStructures/UndirectedGraph.h>

UndirectedGraph::UndirectedGraph() :UndirectedGeneric<Edge>() {}

UndirectedGraph::~UndirectedGraph() {}

bool UndirectedGraph::AddEdge(int vertex1, int vertex2) {
    bool succ1 = InsertEdge(Edge(vertex1, vertex2));
    bool succ2 = true;

    if (succ1 && vertex1 != vertex2) {
        succ2 = InsertEdge(Edge(vertex2, vertex1));
        NR_edges--;
    }
    return succ1 && succ2;
}


#include <DataStructures/Graph.h>
//
//int Graph::mapping(int vertex) {
//    for (int i = 1; i <= 1001; ++i) {   //1~1001是有效映射值
//        if (!used[i]) {  //该映射值还没有用
//            used[i] = true;
//            key[i] = vertex;
//            return i;
//        }
//    }
//    return 0;
//    Assert(0, "Exceed the max number of vertices!\n");
//}
//
//int Graph::Getmap(int vertex) const {
//    auto it = mp.find(vertex);
//    if (it != mp.end()) return it->second;
//    return 0;
//}
//
//Graph::Graph() {
//    memset(used, false, sizeof used);
//    memset(key, 0, sizeof(key));
//    memset(map, 0, sizeof(map));
//    NR_edges = NR_vertices = 0;
//
//    mp.clear();
//}
//
//Graph::~Graph() {
//}
//
//bool Graph::AddVertex(int vertex) {
//    auto it = mp.find(vertex);
//    if (it != mp.end()) {  //存在该点
//        return false;
//    }
//    mp[vertex] = mapping(vertex);
//    NR_vertices++;
//    return true;
//}
//
//bool Graph::RemoveVertex(int vertex) {
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
//            NR_edges--;
//        }
//    }
//    return true;
//}
//
//bool Graph::AddEdge(int vertex1, int vertex2) {
//    auto it1 = mp.find(vertex1);
//    auto it2 = mp.find(vertex2);
//    if (it1 == mp.end() || it2 == mp.end()) {   //有点不存在
//        return false;
//    }
//    vertex1 = it1->second;
//    vertex2 = it2->second;
//
//    if (map[vertex1][vertex2] == 1) return false;   //边存在
//
//    map[vertex1][vertex2] = 1;
//    NR_edges++;
//
//    return true;
//}
//
//bool Graph::RemoveEdge(int vertex1, int vertex2) {
//    auto it1 = mp.find(vertex1);
//    auto it2 = mp.find(vertex2);
//    if (it1 == mp.end() || it2 == mp.end()) {
//        return false;
//    }
//    vertex1 = it1->second;
//    vertex2 = it2->second;
//
//    if (map[vertex1][vertex2] == 0) return false;   //边不存在
//
//    map[vertex1][vertex2] = 0;
//    NR_edges--;
//
//    return true;
//}
//
//int Graph::CountVertices() const {
//    assert(NR_vertices == mp.size());
//    return NR_vertices;
//}
//
//int Graph::CountEdges() const {
//    return NR_edges;
//}
//
//bool Graph::ContainsVertex(int vertex) const {
//    auto it = mp.find(vertex);
//    if (it != mp.end()) return true;
//    return false;
//}
//
//bool Graph::ContainsEdge(int vertex1, int vertex2) const {
//    auto it1 = mp.find(vertex1);
//    auto it2 = mp.find(vertex2);
//    if (it1 != mp.end() && it2 != mp.end() && map[it1->second][it2->second]) {
//        return true;
//    }
//    return false;
//}
//
//std::vector<int> Graph::GetVertices() const {
//    std::vector<int> allvertices;
//    for (auto it = mp.begin(); it != mp.end(); ++it) {
//        allvertices.push_back(it->first);
//    }
//    return allvertices;
//}
//
//std::vector<Edge> Graph::GetEdges() const {
//    std::vector<Edge> alledges;
//    for (int i = 1; i < MAXV; ++i) {
//        for (int j = 1; j < MAXV; ++j) {
//            if (map[i][j]) {
//                alledges.emplace_back(Edge(key[i], key[j]));
//            }
//        }
//    }
//    return alledges;
//}
//
//std::vector<Edge> Graph::GetIncomingEdges(int vertex) const {
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
//std::vector<Edge> Graph::GetOutgoingEdges(int vertex) const {
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
//int Graph::GetDegree(int vertex) const {
//    auto it = mp.find(vertex);
//    if (it == mp.end()) return 0;
//    vertex = it->second;
//
//    int ans = 0;
//    for (int i = 1; i < MAXV; ++i) {
//        if (map[vertex][i]) ans++;
//    }
//    return ans;
//}
//
//std::vector<int> Graph::GetNeighbors(int vertex) const {
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

bool Graph::AddEdge(int vertex1, int vertex2) {
    Edge e = Edge(vertex1, vertex2);
    return InsertEdge(e);
}

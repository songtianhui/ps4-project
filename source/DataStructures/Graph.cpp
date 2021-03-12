#include <DataStructures/Graph.h>
#include <cassert>

void Graph::update_list() {
    int n = 0;
    for (int i = 0; i < MAXV; ++i) {
        if (exist[i]) {
            for (auto it = edges[i].begin(); it != edges[i].end();) {
                if (!map[i][*it]) it = edges[i].erase(it);
                else n++, it++;
            }
        }
    }
    assert(n == NR_edges);
}

int Graph::mapping(int vertex) {
    for (int i = 1; i < MAXV; ++i) {
        if (exist[i] == 0) {  //该映射值还没有用
            exist[i] = vertex;
            return i;
        }
    }
    Assert(0, "Exceed the max number of vertices!\n");
}

Graph::Graph() {
    memset(exist, 0, sizeof(exist));
    memset(map, 0, sizeof(map));
    for (int i = 0; i < MAXV; ++i) edges[i].clear();
    NR_edges = NR_vertices = 0;

    mp.clear();
}

Graph::~Graph() {
}

bool Graph::AddVertex(int vertex) {
    auto it = mp.find(vertex);
    if (it != mp.end()) {  //存在该点
        return false;
    }
    mp[vertex] = mapping(vertex);
    NR_vertices++;
    edges[mp[vertex]].clear();
    return true;
}

bool Graph::RemoveVertex(int vertex) {
    auto it = mp.find(vertex);
    if (it != mp.end()) { //存在该点
        vertex = mp[vertex];
        mp.erase(it);       //映射值取消
        exist[vertex] = 0;

        NR_vertices--;
        edges[vertex].clear();
        for (int i = 0; i < MAXV; ++i) {
            if (map[vertex][i]) {
                map[vertex][i] = 0;
                NR_edges--;
            }
            if (map[i][vertex]) {
                map[i][vertex] = 0;
                NR_edges--;
            }
        }
        //update_list();
        //邻接链表也要删不过有点烦？
        return true;
    }
    return false;
}

bool Graph::AddEdge(int vertex1, int vertex2) {
    auto it1 = mp.find(vertex1);
    auto it2 = mp.find(vertex2);
    if (it1 == mp.end() || it2 == mp.end()) {
        return false;
    }
    vertex1 = mp[vertex1];
    vertex2 = mp[vertex2];

    if (map[vertex1][vertex2] == 1) return false;

    map[vertex1][vertex2] = 1;
    edges[vertex1].push_back(vertex2);
    NR_edges++;
    return true;
}

bool Graph::RemoveEdge(int vertex1, int vertex2) {
    auto it1 = mp.find(vertex1);
    auto it2 = mp.find(vertex2);
    if (it1 == mp.end() || it2 == mp.end()) {
        return false;
    }

    vertex1 = mp[vertex1];
    vertex2 = mp[vertex2];

    if (map[vertex1][vertex2] == 0) return false;

    map[vertex1][vertex2] = 0;
    NR_edges--;
    //update_list();
//  for (auto it=edges[vertex1].begin(); it != edges[vertex1].end(); ) {
//    if (*it == vertex2) {
//      it = edges[vertex1].erase(it);
//    } else {
//      ++it;
//    }
//  }
    return true;
}

int Graph::CountVertices() const {
    return NR_vertices;
}

int Graph::CountEdges() const {
    return NR_edges;
}

bool Graph::ContainsVertex(int vertex) const {
    auto it = mp.find(vertex);
    if (it != mp.end()) return true;
    return false;
}

bool Graph::ContainsEdge(int vertex1, int vertex2) const {
    auto it1 = mp.find(vertex1);
    auto it2 = mp.find(vertex2);
    if (it1 != mp.end() && it2 != mp.end() && map[it1->second][it2->second]) {
        return true;
    }
    return false;
}

std::vector<int> Graph::GetVertices() const {
    std::vector<int> allvertices;
    for (int i = 1; i < MAXV; ++i) {
        if (exist[i]) allvertices.push_back(exist[i]);
    }
    return allvertices;
}

std::vector<Edge> Graph::GetEdges() const {
    std::vector<Edge> alledges;
    for (int i = 1; i < MAXV; ++i) {
        for (int j = 1; j < MAXV; ++j) {
            if (map[i][j]) {
                alledges.push_back(Edge(exist[i], exist[j]));
            }
        }
    }
    return alledges;
}

std::vector<Edge> Graph::GetIncomingEdges(int vertex) const {
    std::vector<Edge> ret;
    auto it = mp.find(vertex);
    if (it == mp.end()) return ret;
    vertex = it->second;

    for (int i = 1; i < MAXV; ++i) {
        if (map[i][vertex]) {
            ret.push_back(Edge(exist[i], it->first));
        }
    }
    return ret;
}

std::vector<Edge> Graph::GetOutgoingEdges(int vertex) const {
    std::vector<Edge> ret;
    auto it = mp.find(vertex);
    if (it == mp.end()) return ret;
    vertex = it->second;

    for (int next: edges[vertex]) {
        ret.push_back(Edge(it->first, exist[next]));
    }
    return ret;
}

int Graph::GetDegree(int vertex) const {
    if (mp.find(vertex) == mp.end()) return 0;
    return edges[vertex].size();
}

std::vector<int> Graph::GetNeighbors(int vertex) const {
    std::vector<int> a;
    if (mp.find(vertex) == mp.end()) return a;
    return edges[vertex];
}


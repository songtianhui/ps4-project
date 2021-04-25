#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <cassert>
#include <optional>
#include <map>
#include <set>

template<class TGraph>
class ShortestPaths {

private:
    const TGraph *g;
    int src;

protected:
    typedef typename TGraph::value_type Tvalue;

public:
    ShortestPaths() = delete;

    ShortestPaths(const TGraph *graph, int source) {
        g = graph;
        src = source;
    }

    virtual ~ShortestPaths() {}

public:
    virtual bool HasPathTo(int destination) const {return false;}

    virtual std::optional<Tvalue> TryGetDistanceTo(int destination) const {return std::nullopt;}

    virtual std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const {return std::nullopt;}

    int GetSource() const {
        return src;
    }
};

#endif

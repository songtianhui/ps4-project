#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <cassert>
#include <optional>
#include <map>
#include <set>
#include <unordered_set>
#include <type_traits>

template<class TGraph>
class ShortestPaths {

private:
    const TGraph *g;
    int src;
    typedef typename TGraph::value_type Tvalue;
    static_assert(std::is_default_constructible<Tvalue>::value,
                  "Data structure requires default-constructible elements");

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

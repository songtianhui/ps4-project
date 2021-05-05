#ifndef MULTI_SOURCE_SHORTEST_PATHS
#define MULTI_SOURCE_SHORTEST_PATHS

#include <vector>
#include <optional>
#include <cassert>

template<typename TGraph>
class MultiSourceShortestPaths {
private:
    const TGraph *g;
    typedef typename TGraph::value_type TValue;
    static_assert(std::is_default_constructible<TValue>::value,
                  "TValue requires default constructor");

public:
    MultiSourceShortestPaths() = delete;

    explicit MultiSourceShortestPaths(const TGraph *graph) {
        g = graph;
    }

    virtual ~MultiSourceShortestPaths() {}

public:
    virtual bool HasPathTo(int source, int destination) const { return false; }

    virtual std::optional<TValue> TryGetDistanceTo(int source, int destination) const { return std::nullopt; }

    virtual std::optional<std::vector<int>> TryGetShortestPathTo(int source, int destination) const { return std::nullopt; }
};

#endif

#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <cassert>
#include <optional>
#include <map>
#include <set>

template<template<typename> class TGraph, typename TValue>
class ShortestPaths {
private:
    TGraph<TValue> *g;
    int src;

public:
    ShortestPaths() = delete;

    ShortestPaths(const TGraph<TValue> *graph, int source) {
        g = graph;
        src = source;
    }

    virtual ~ShortestPaths();

public:
    virtual bool HasPathTo(int destination) const;

    virtual std::optional<TValue> TryGetDistanceTo(int destination) const;

    virtual std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const;

public:
    int GetSource() {
        return src;
    }
};

#endif

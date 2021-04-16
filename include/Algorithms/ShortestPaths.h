#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <optional>

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
    bool HasPathTo(int destination) const {

    }

    std::optional<TValue> TryGetDistanceTo(int destination) const;

    std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const;
};

#endif

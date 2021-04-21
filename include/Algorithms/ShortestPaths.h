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
    const TGraph<TValue> *g;
    int src;

public:
    ShortestPaths() = delete;

    ShortestPaths(const TGraph<TValue> *graph, int source) {
        g = graph;
        src = source;
    }

    virtual ~ShortestPaths() {}

public:
    virtual bool HasPathTo(int destination) const {return false;}

    virtual std::optional<TValue> TryGetDistanceTo(int destination) const {return std::nullopt;}

    virtual std::optional<std::vector<int>> TryGetShortestPathTo(int destination) const {return std::nullopt;}

    int GetSource() const {
        return src;
    }
};

#endif
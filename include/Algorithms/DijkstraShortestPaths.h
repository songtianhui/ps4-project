//
// Created by sth on 2021/4/15.
//

#ifndef GRAPHLIBRARY_DIJKSTRASHORTESTPATHS_H
#define GRAPHLIBRARY_DIJKSTRASHORTESTPATHS_H

#include <Algorithms/ShortestPaths.h>

template<template<typename> class TGraph, typename TValue>
class DijkstraShortestPaths : public ShortestPaths<TGraph, TValue> {
private:
    std::map<int, std::optiona<TValue> > dis;   // src到点的距离
    std::map<int, std::optional<int> >   pre;   // src到点最短路径的该点前一个点

public:
    DijkstraShortestPaths() = delete;

    DijkstraShortestPaths(const TGraph<TValue>, *graph, int source) : ShortestPaths(graph, source) {
    }

    virtual ~DijkstraShortestPaths();

public:
    std::optional<TValue> TryGetDistanceTo(int destination) const override {

    }

    std::optional<std::vector<int> > TryGetShortestPathTo(int destination) const override {

    }
};

#endif //GRAPHLIBRARY_DIJKSTRASHORTESTPATHS_H

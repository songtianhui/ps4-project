//
// Created by sth on 2021/4/15.
//

#ifndef GRAPHLIBRARY_DIJKSTRASHORTESTPATHS_H
#define GRAPHLIBRARY_DIJKSTRASHORTESTPATHS_H

#include <Algorithms/ShortestPaths.h>

template<template<typename> class TGraph, typename TValue>
class DijkstraShortestPaths : public ShortestPaths<TGraph, TValue> {
public:
    DijkstraShortestPaths() = delete;

    DijkstraShortestPaths(const TGraph<TValue>, *graph, int source) : ShortestPaths(graph, source) {

    }

    virtual ~DijkstraShortestPaths();
};

#endif //GRAPHLIBRARY_DIJKSTRASHORTESTPATHS_H

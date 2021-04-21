//
// Created by sth on 2021/4/21.
//


#include <Algorithms/DijkstraShortestPaths.h>
#include <DataStructures/WeightedGraph.h>

WeightedGraph<double> g;

int main() {

    DijkstraShortestPaths<WeightedGraph, double> ssp(&g, 1);

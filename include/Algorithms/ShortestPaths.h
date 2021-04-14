#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <optional>

template <template<typename> class TGraph, typename TValue>
class ShortestPaths {
 public:
  ShortestPaths(const TGraph<TValue> *graph, int source);
  virtual ~ShortestPaths();
 public:
  bool HasPathTo(int destination);
  std::optional<TValue> TryGetDistanceTo(int destination);
  std::optional<std::vector<int>> TryGetShortestPathTo(int destination);
};

#endif

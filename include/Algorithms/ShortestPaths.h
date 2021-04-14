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
  virtual bool HasPathTo(int destination) = 0;
  virtual std::optional<TValue> GetDistanceTo(int destination) = 0;
  virtual std::optional<std::vector<int>> GetShortestPathTo(int destination) = 0;
};

#endif

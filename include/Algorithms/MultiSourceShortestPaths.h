#ifndef SHORTEST_PATHS
#define SHORTEST_PATHS

#include <vector>
#include <optional>

template <typename TGraph>
class MultiSourceShortestPaths {
 public:
  MultiSourceShortestPaths() = delete;
  MultiSourceShortestPaths(const TGraph<TValue> *graph);
  virtual ~MultiSourceShortestPaths();
 public:
  bool HasPathTo(int source, int destination) const;
  std::optional<TValue> TryGetDistanceTo(int source, int destination) const;
  std::optional<std::vector<int>> TryGetShortestPathTo(int source, int destination) const;
};

#endif

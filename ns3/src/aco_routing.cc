#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

struct Link {
  int src, dst;
  double pheromone;
  double reliability;
};

class ACORouting {
public:
  ACORouting(int n, std::vector<Link> links)
      : numNodes(n), linkTable(std::move(links)) {}

  std::vector<int> FindBestPath(int src, int dst) {
    std::vector<int> path;
    int current = src;
    path.push_back(src);

    while (current != dst) {
      auto next = SelectNext(current);
      if (next == -1)
        break;
      path.push_back(next);
      current = next;
    }
    UpdatePheromone(path);
    return path;
  }

private:
  int numNodes;
  std::vector<Link> linkTable;

  int SelectNext(int node) {
    double maxScore = -1;
    int best = -1;
    for (auto &l : linkTable) {
      if (l.src == node) {
        double score = l.pheromone * l.reliability;
        if (score > maxScore) {
          maxScore = score;
          best = l.dst;
        }
      }
    }
    return best;
  }

  void UpdatePheromone(const std::vector<int> &path) {
    for (size_t i = 0; i < path.size() - 1; ++i) {
      for (auto &l : linkTable) {
        if (l.src == path[i] && l.dst == path[i + 1])
          l.pheromone = 0.9 * l.pheromone + 0.1;
      }
    }
  }
};

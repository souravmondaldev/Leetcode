class FenwickTree {
 private:
  vector<int> tree;

  static int lowbit(int index) {
    return index & -index;
  }
 public:
  FenwickTree(int size)  {
    tree.resize(size);
  }

  void update(int index, int value) {
    while (index < tree.size()) {
      tree[index] = max(tree[index], value);
      index += lowbit(index);
    }
  }

  int query(int index) const {
    int maxGap = 0;
    while (index > 0) {
      maxGap = max(maxGap, tree[index]);
      index -= lowbit(index);
    }
    return maxGap;
  }

 
};

class Solution {
 public:
  vector<bool> getResults(vector<vector<int>>& queries) {
    int maxIndex = min(50000, (int)(queries.size()) * 3);
    vector<bool> results;
    FenwickTree fenwick(maxIndex + 1);
    // set<int> obstacles{0, maxIndex};  
    set<int> obstacles{0};

    // Precompute gaps between obstacles.
    for (const auto& query : queries) {
      if (query[0] == 1) {  // Add obstacle.
        const int position = query[1];
        obstacles.insert(position);
      }
    }

    // Populate Fenwick Tree with initial gaps.
    int current = 0;
    for (auto it = obstacles.begin(); it != obstacles.end(); ++it) {
      int nextObstacle = *next(it);
      fenwick.update(nextObstacle, nextObstacle - current);
      current = nextObstacle;
    }

    // Process queries in reverse order.
    for (int i = queries.size() - 1; i >= 0; --i) {
      const auto& query = queries[i];
      const int queryType = query[0];
      const int position = query[1];

      if (queryType == 1) {  // Remove obstacle.
        auto it = obstacles.find(position);
        if (next(it) != obstacles.end()) {
          // Update the gap between adjacent obstacles.
          fenwick.update(*next(it), *next(it) - *prev(it));
        }
        obstacles.erase(it);
      } else if (queryType == 2) {  // Check if block fits.
        const int blockSize = query[2];
        auto it = obstacles.upper_bound(position);
        const int previousObstacle = *prev(it);
        results.push_back(fenwick.query(previousObstacle) >= blockSize ||
                          position - previousObstacle >= blockSize);
      }
    }

    // Reverse results to match original query order.
    return {results.rbegin(), results.rend()};
  }
};

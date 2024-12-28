#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    bool inBounds(int i, int j, int n, int m) {
        return (0 <= i && i < n && 0 <= j && j < m);
    }

    bool ok(vector<vector<int>>& grid, vector<vector<int>>& dist, int wait_time) {
        int n = grid.size();
        int m = grid[0].size();

        queue<tuple<int, int, int>> q;
        q.push({0, 0, wait_time});

        vector<vector<int>> visited(n, vector<int>(m, 0));
        visited[0][0] = 1;

        vector<vector<int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [x, y, t] = q.front();
            q.pop();

            for (auto& move : moves) {
                int newX = x + move[0], newY = y + move[1];

                // Check bounds, visited, obstacles, and fire constraints
                if (!inBounds(newX, newY, n, m) || visited[newX][newY] || grid[newX][newY] == 2) 
                    continue;

                // If we can reach the bottom-right safely
                if (newX == n - 1 && newY == m - 1 && dist[newX][newY] >= t + 1) 
                    return true;

                // If fire will reach before we can
                if (dist[newX][newY] <= t + 1) 
                    continue;

                q.push({newX, newY, t + 1});
                visited[newX][newY] = 1;
            }
        }
        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Distance grid to track fire spread times
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        queue<tuple<int, int, int>> fireQueue;

        // Initialize fire spread times
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) { // Fire source
                    fireQueue.push({i, j, 0});
                    dist[i][j] = 0;
                }
            }
        }

        // Spread fire using BFS
        vector<vector<int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!fireQueue.empty()) {
            auto [x, y, t] = fireQueue.front();
            fireQueue.pop();

            for (auto& move : moves) {
                int newX = x + move[0], newY = y + move[1];

                if (!inBounds(newX, newY, n, m) || grid[newX][newY] == 2 || dist[newX][newY] <= t + 1) 
                    continue;

                dist[newX][newY] = t + 1;
                fireQueue.push({newX, newY, t + 1});
            }
        }

        // Binary search for the maximum safe delay
        int left = 0, right = 1000000000, ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (ok(grid, dist, mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    void bfs(vector<vector<int>>& grid, unordered_map<int, int>& colorCount,
             int row, int col, int color) {
        queue<pair<int, int>> q;

        q.push({row, col});
        grid[row][col] = color;
        colorCount[color]++;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto top = q.front();
                q.pop();
                for (auto direction : directions) {
                    int newRow = top.first + direction[0];
                    int newCol = top.second + direction[1];
                    if (newRow >= 0 && newCol >= 0 && newRow < grid.size() &&
                        newCol < grid[0].size() && grid[newRow][newCol] == 1) {
                        q.push({newRow, newCol});
                        grid[newRow][newCol] = color;
                        colorCount[color]++;
                    }
                }
            }
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int color = 2;
        unordered_map<int, int> colorCount;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    bfs(grid, colorCount, i, j, color);
                    color++;
                }
            }
        }
        int maxIsland = 0;
        for (auto [color, count] : colorCount) {
            maxIsland = max(maxIsland, count);
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    cout << "going here" << endl;
                    int island = 1;
                    unordered_set<int> seenColors;
                    for (auto dir : directions) {

                        int row = dir[0] + i, col = dir[1] + j;
                        if (row >= 0 && col >= 0 && row < grid.size() &&
                            col < grid[0].size() && grid[row][col] != 0 &&
                            seenColors.find(grid[row][col]) ==
                                seenColors.end()) {
                            if (row >= 0 && col >= 0 && row < n && col < m &&
                                grid[row][col] != 0) {
                                int neighborColor = grid[row][col];
                                // Only add the island's area if we haven't seen
                                // its color before
                                if (seenColors.find(neighborColor) ==
                                    seenColors.end()) {
                                    island += colorCount[neighborColor];
                                    seenColors.insert(neighborColor);
                                }
                            }
                        }
                    }
                    maxIsland = max(maxIsland, island);
                }
            }
        }
        if (colorCount.empty())
            return 1;
        return maxIsland;
    }
};
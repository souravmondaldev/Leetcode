class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Initialize the DP cache with -1 to mark unseen states
        vector<vector<vector<int>>> dpCache(m, vector<vector<int>>(n, vector<int>(n, -1)));
        
        // Start the DP calculation
        return dp(0, 0, n - 1, grid, dpCache);
    }

private:
    int dp(int row, int col1, int col2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dpCache) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Base case: if out of bounds
        if (col1 < 0 || col1 >= n || col2 < 0 || col2 >= n) {
            return 0;
        }
        
        // Check if result is already cached
        if (dpCache[row][col1][col2] != -1) {
            return dpCache[row][col1][col2];
        }
        
        // Current cell cherries
        int result = grid[row][col1];
        if (col1 != col2) {
            result += grid[row][col2];
        }
        
        // Transition to the next row
        if (row != m - 1) {
            int maxCherries = 0;
            for (int newCol1 = col1 - 1; newCol1 <= col1 + 1; newCol1++) {
                for (int newCol2 = col2 - 1; newCol2 <= col2 + 1; newCol2++) {
                    maxCherries = max(maxCherries, dp(row + 1, newCol1, newCol2, grid, dpCache));
                }
            }
            result += maxCherries;
        }

        dpCache[row][col1][col2] = result;
        return result;
    }
};

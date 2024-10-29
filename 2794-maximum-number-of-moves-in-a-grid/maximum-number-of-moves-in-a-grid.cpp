class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int maxMoves = 0;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        for (int row = 0; row < n; ++row) {
            maxMoves = max(maxMoves, solve(grid, dp, row, 0));
        }
        
        return maxMoves;
    }
    
    int solve(vector<vector<int>>& grid, vector<vector<int>>& dp, int row, int col) {
        int n = grid.size(), m = grid[0].size();
        
        if (col == m - 1) return 0; // Reached the last column, no further moves possible
        if (dp[row][col] != -1) return dp[row][col];
        
        int maxMove = 0;
        
        // Move to (row - 1, col + 1)
        if (row > 0 && grid[row][col] < grid[row - 1][col + 1]) {
            maxMove = max(maxMove, 1 + solve(grid, dp, row - 1, col + 1));
        }
        
        // Move to (row, col + 1)
        if (grid[row][col] < grid[row][col + 1]) {
            maxMove = max(maxMove, 1 + solve(grid, dp, row, col + 1));
        }
        
        // Move to (row + 1, col + 1)
        if (row < n - 1 && grid[row][col] < grid[row + 1][col + 1]) {
            maxMove = max(maxMove, 1 + solve(grid, dp, row + 1, col + 1));
        }
        
        dp[row][col] = maxMove;
        return maxMove;
    }
};

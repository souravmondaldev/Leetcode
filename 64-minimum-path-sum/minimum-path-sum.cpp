class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0)
            return 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return minPath(grid, dp, n, m);
    }
    int minPath(vector<vector<int>>& grid, vector<vector<int>>& dp, int n, int m){
        if(n < 1 || m < 1)
            return INT_MAX;
        if(n == 1 && m == 1)
            return grid[0][0];
        if(dp[n][m] != -1)
            return dp[n][m];
        return dp[n][m] = grid[n - 1][m - 1] + min(minPath(grid, dp, n - 1, m),
            minPath(grid, dp, n, m - 1));
    }
    
};
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return paths(n, m , dp);
    }
    int paths(int n, int m, vector<vector<int>> &dp){
        if(n<= 1 || m <= 1) return 1;
        if(dp[n][m] != -1)
            return dp[n][m];
        return dp[n][m] = paths(n - 1, m, dp) + paths(n, m - 1, dp);
    }
};
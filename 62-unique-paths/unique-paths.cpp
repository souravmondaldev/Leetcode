class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        // return paths(n, m , dp);
        return nCr(n + m - 2, min(n - 1, m - 1));
    }
    int nCr(int n, int r){
        long int result = 1;
        for(int i = 0; i < r; i ++){
            result *= (n - i);
            result /= (i + 1);
        }
        return result;
    }
    int paths(int n, int m, vector<vector<int>> &dp){
        if(n<= 1 || m <= 1) return 1;
        if(dp[n][m] != -1)
            return dp[n][m];
        return dp[n][m] = paths(n - 1, m, dp) + paths(n, m - 1, dp);
    }
};
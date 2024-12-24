class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        // int dp[n + 1][m + 1];
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        // return recur(text1, text2, n - 1, m - 1, dp);
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 0; i < n ; i ++){
            for(int j = 0; j < m; j ++){
                if(text1[i] == text2[j]){
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                }
                else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        return dp[n][m];
    }
    int recur(string text1, string text2, int n, int m, vector<vector<int>> &dp){
        if(n == 0 || m == 0)
            return 0;
        if(dp[n][m] != -1)
            return dp[n][m];
        if(text1[n] == text2[m])
            dp[n][m] = recur(text1, text2, n - 1, m - 1, dp) + 1;
        else dp[n][m] = max(recur(text1, text2, n - 1, m, dp), recur(text1, text2, n, m - 1, dp));
        return dp[n][m];
    }
};
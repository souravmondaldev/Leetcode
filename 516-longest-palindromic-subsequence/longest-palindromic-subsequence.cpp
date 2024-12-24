class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string revesedStr = s;
        reverse(revesedStr.begin(), revesedStr.end());
        return longestCommonSubstr(s, revesedStr);
    }

    int longestCommonSubstr(string str1, string str2){
        int n = str1.length(), m = str2.length();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(str1[i] == str2[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        return dp[n][m];
    }
};
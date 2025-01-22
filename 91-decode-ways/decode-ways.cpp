
class Solution {
public:
    int df(string s, int pos, vector<int>& dp) {
        if (pos == s.size())
            return 1;
        if (s[pos] == '0')
            return 0;

        if (dp[pos] != -1)
            return dp[pos];

        int count = df(s, pos + 1, dp);
        if (pos < s.size() - 1 && s.substr(pos, 2) < "27") {
            count += df(s, pos + 2, dp);
        }
        return dp[pos] = count;
    }
    int numDecodings(string s) {
        vector<int> dp(s.size() + 1, -1);
        return df(s, 0, dp);
    }
};
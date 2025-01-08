class Solution {
    int MOD = 1e9 + 7;
    int dp[101][202][101];
public:
    int ways(int idx, int profit, int used, int minProfit, int n, vector<int>& group, vector<int>& profits){
        if(used > n) return 0;
        if(dp[idx][min(profit, minProfit)][used] != -1) return dp[idx][min(profit, minProfit)][used];
        if(idx == profits.size()){
            if(profit >= minProfit)
                return 1;
            else return 0;
        }
        int take = ways(idx + 1, profit + profits[idx], used + group[idx],  minProfit, n, group, profits) % MOD;
        int notTake = ways(idx + 1, profit, used,  minProfit, n, group, profits)% MOD;

        return dp[idx][min(profit, minProfit)][used] = (take + notTake)% MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return ways(0, 0, 0, minProfit, n, group, profit);
    }
};
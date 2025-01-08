class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        return findMinimumCost(1, c, cuts, dp);
    }

    int findMinimumCost(int start, int end, vector<int>&cuts, vector<vector<int>>&dp){
        if(start > end) return 0;
        if(dp[start][end] != -1) return dp[start][end];

        int minCut = INT_MAX;
        for(int idx = start; idx <= end; idx ++){
            int currentMinCut = cuts[end + 1] - cuts[start - 1]
                + findMinimumCost(start, idx - 1, cuts, dp)
                + findMinimumCost(idx + 1, end, cuts, dp);
            minCut = min(minCut, currentMinCut);
        }

        return dp[start][end] = minCut;
    }
};
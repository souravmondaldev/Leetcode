class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int N = piles.size();
        // return true;
        vector<vector<int>> dp(N + 1, vector<int>(N + 1, -1));
        return optimalPick(0, N - 1, dp, piles);
    }
    int optimalPick(int left, int right, vector<vector<int>> &dp, vector<int>& piles){
        if(left > right){
            return 0;
        }
        if(dp[left][right] != -1)
            return dp[left][right];
        int isAlicePicking = (right - left) % 2;
        int leftPick = isAlicePicking ? piles[left] : 0;
        int rightPick = isAlicePicking ? piles[right] : 0;
        return dp[left][right] = max(
            optimalPick(left + 1, right, dp, piles) + leftPick,
            optimalPick(left, right - 1, dp, piles) + rightPick);
    }
};
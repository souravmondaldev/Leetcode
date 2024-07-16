class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> dp(n, 0);
        vector<int> houses(n, 0);
        for(int num : nums){
            houses[num] += num;
        }
        dp[1] = houses[1];
        for(int i = 2; i < n ; i ++){
            dp[i] = max(houses[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }
};
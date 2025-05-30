class Solution {
public:
    vector<vector<int>> dp;

    int solve(vector<int>& nums, int i, int target){
        if(target == 0) return 0;                          // when target is zero that means we found set of elements that sum up to target   
        if(target < 0 || i >= nums.size()) return -1001;   // if target is less then 0 or i is greater than nums size then its invalid case and just return with very small number     
        if(dp[i][target] != - 1) return dp[i][target];     // if already seen this condition then just return the stored result
        int take = 1 + solve(nums, i+1, target - nums[i]); // when we take, we add 1 to the count and decrease target by nums[i]
        int notTake = solve(nums, i+1, target);            // when not-take, simple move to next element
        return dp[i][target] = max(take, notTake);         // save the max result for future use
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        dp.resize(1001, vector<int>(1001, -1));            // initialise dp with -1
        int ans = solve(nums, 0, target);                  // get the result with starting i = 0
        return (ans > 0)?ans: -1;                          // return -1 if the ans is less than equal to 0, otherwise return ans
    }
};
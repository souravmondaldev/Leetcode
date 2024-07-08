class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n + 1, -1);
        return robOpt(n, nums, memo);
    }
    int robOpt(int i, vector<int> &nums, vector<int> &memo){
        if(i < 1)
            return 0;
        if(memo[i] != -1)
            return memo[i];
        return memo[i] = max( robOpt(i - 1, nums, memo),
                            nums[i - 1] + robOpt(i - 2, nums, memo));
    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        for(int num : nums){
            int currRob = max(rob1 + num, rob2);
            rob1 = rob2;
            rob2 = currRob;
        }
        return max(rob1, rob2);
    }
    int robOpt(int i, vector<int> &nums, vector<int> &memo){
        if(i < 1)
            return 0;
        if(memo[i] != -1)
            return memo[i];
        return memo[i] = max(robOpt(i - 1, nums, memo),
                            nums[i - 1] + robOpt(i - 2, nums, memo));
    }
};
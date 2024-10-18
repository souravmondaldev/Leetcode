class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOrValue = 0;
        for(int num : nums){
            maxOrValue |= num;
        }
        vector<vector<int>> memo(nums.size(), vector<int> (maxOrValue + 1, -1));
        return bruteForceSubsets(nums, 0, 0, maxOrValue, memo);
    }
    int bruteForceSubsets(vector<int> &nums, int idx , int currentOr, int targetOr, vector<vector<int>>& memo){
        if(idx == nums.size()){
            return currentOr == targetOr ? 1 : 0;
        }
        if(memo[idx][currentOr] != -1)
            return memo[idx][currentOr];
        int countWithout = bruteForceSubsets(nums, idx + 1, currentOr, targetOr, memo);
        int countWith = bruteForceSubsets(nums, idx + 1, currentOr | nums[idx], targetOr, memo);
        return memo[idx][currentOr] = countWith + countWithout;
    }
};
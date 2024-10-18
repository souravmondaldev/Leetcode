class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOrValue = 0;
        for(int num : nums){
            maxOrValue |= num;
        }
        return bruteForceSubsets(nums, 0, 0, maxOrValue);
    }
    int bruteForceSubsets(vector<int> &nums, int idx , int currentOr, int targetOr){
        if(idx == nums.size()){
            return currentOr == targetOr ? 1 : 0;
        }
        int countWithout = bruteForceSubsets(nums, idx + 1, currentOr, targetOr);
        int countWith = bruteForceSubsets(nums, idx + 1, currentOr | nums[idx], targetOr);
        return countWith + countWithout;
    }
};
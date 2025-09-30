class Solution {
public:
    //O(N) O(1)
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<vector<int>>  ranges;
        if(nums.empty()){
            return {{lower, upper}};
        }
        if(nums[0] > lower){
            ranges.push_back({lower, nums[0] - 1});
        }
        for(int i = 1; i < nums.size(); i ++){
            if(nums[i] - nums[i - 1] > 1){
                ranges.push_back({nums[i - 1] + 1, nums[i] - 1});
            }
        }
        if(nums.back() < upper){
            ranges.push_back({nums.back() + 1, upper});
        }
        return ranges;
    }
};
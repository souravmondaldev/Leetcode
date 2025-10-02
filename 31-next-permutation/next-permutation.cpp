class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int idx = nums.size() - 2;
        while(idx >= 0 && nums[idx] >= nums[idx + 1])
            idx --;
        if(idx >= 0){
            int j = nums.size() - 1;
            while(nums[j] <= nums[idx]){
                j --;
            }
            swap(nums[idx], nums[j]);
        }
        reverse(nums.begin() + idx + 1, nums.end());
    }
};
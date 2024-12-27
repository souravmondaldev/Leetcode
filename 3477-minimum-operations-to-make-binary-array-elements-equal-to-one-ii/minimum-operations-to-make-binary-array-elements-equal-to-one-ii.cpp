class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n= nums.size(), flips = 0;
        for(int i = 0; i < n; i ++){
            nums[i] = (nums[i] + flips) % 2;
            if(nums[i] == 0){
                flips ++;
            }
        }
        return flips;
    }
};
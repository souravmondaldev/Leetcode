class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long count = 0; 
        int min_pos = -1, max_pos = -1, last_bound = -1;
        for(int i = 0; i < nums.size(); i ++){
            if(nums[i] == minK)
                min_pos = i;
            if(nums[i] == maxK)
                max_pos = i;
            if(nums[i] < minK || nums[i] > maxK){
                last_bound = i;
                min_pos = -1;
                max_pos = -1;
            }
            if(min_pos != -1 && max_pos != -1){
                count += min(min_pos, max_pos) - last_bound;
            }
        }
        return count;
    }
};
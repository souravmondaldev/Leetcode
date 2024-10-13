class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0;
        int minSize = INT_MAX;
        while(right < nums.size()){
            sum += nums[right ++];
            while(sum >= target){
                minSize = min(minSize, right - left);
                sum -= nums[left++];
            }
        }
        return minSize == INT_MAX ? 0 : minSize;
    }
};
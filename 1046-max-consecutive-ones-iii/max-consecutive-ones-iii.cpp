class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, count = 0, n = nums.size(), ans = 0;
        for(int right = 0; right < n; right ++){
            if(nums[right] == 0){
                count ++;
            }
            if(count > k){
                if(nums[left] == 0){
                    count --;
                }
                left ++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
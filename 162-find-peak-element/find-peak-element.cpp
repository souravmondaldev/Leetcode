class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // for(int i = 0; i < nums.size() - 1; i ++){
        //     if(nums[i] > nums[i + 1])   return i;
        // }
        // return nums.size() - 1;
        int left = 0, right = nums.size() - 1;
        while(left < right){
            int mid = (right - left) / 2 + left ;
            if(nums[mid] > nums[mid + 1]){
                right = mid;
            }
            else left = mid + 1;
        }
        return left;
    }
};
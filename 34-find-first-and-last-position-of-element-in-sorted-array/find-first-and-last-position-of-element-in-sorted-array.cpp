class Solution {
public:
    int findBound(vector<int> nums, int target, bool isFirst){
        int n = nums.size();
        int left = 0, right = n - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                if(isFirst){
                    if(mid == 0 || nums[mid - 1] != target)
                        return mid;
                    right = mid - 1;
                }
                else{
                    if(mid == n - 1 || nums[mid + 1] != target)
                        return mid;
                    left = mid + 1;
                }
            } 
            else if(nums[mid] > target)   right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       int firstOccurance = findBound(nums, target, true);
       if(firstOccurance == -1)
        return {-1, -1};
       int secondOccurance = findBound(nums, target, false);
       return {firstOccurance, secondOccurance};
    }
};
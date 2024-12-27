class Solution {
public:
    int minSubarrayRequired(int maxSumAllowed, vector<int> &nums){
        int currSum = 0, splits = 1;
        for(int num : nums){
            if(currSum + num <= maxSumAllowed){
                currSum += num;
            }
            else {
                currSum = num;
                splits ++;
            }
        }
        return splits;
    }
    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        int maxEl = INT_MIN;
        for(int num : nums){
            sum += num;
            maxEl = max(maxEl, num);
        }
        int minLargestSplit = 0;
        int left = maxEl, right = sum;
        while(left <= right){
            int maxSumAllowed = left + (right - left) / 2;
            if(minSubarrayRequired(maxSumAllowed, nums) <= k){
                right = maxSumAllowed - 1;
                minLargestSplit = maxSumAllowed;
            }
            else left = maxSumAllowed + 1;
        }
        return minLargestSplit;
    }
};
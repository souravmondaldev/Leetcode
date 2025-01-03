class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        // Use long long to handle large sums and avoid overflow
        long long sumOfAll = 0;
        for (int num : nums) {
            sumOfAll += num;
        }

        int validSplit = 0;
        long long currSum = 0;

        // Iterate through the array to calculate valid splits
        for (int i = 0; i < nums.size() - 1; i++) {
            currSum += nums[i];
            // Check if the left sum is greater than or equal to the right sum
            if (currSum >= sumOfAll - currSum) {
                validSplit++;
            }
        }
        return validSplit;
    }
};

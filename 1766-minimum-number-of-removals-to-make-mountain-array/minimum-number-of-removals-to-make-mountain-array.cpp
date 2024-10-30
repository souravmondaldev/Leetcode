class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Compute the Longest Increasing Subsequence (LIS) from the left
        vector<int> lis(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }
        
        // Step 2: Compute the Longest Decreasing Subsequence (LDS) from the right
        vector<int> lds(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = n - 1; j > i; j--) {
                if (nums[i] > nums[j]) {
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }
        
        // Step 3: Find the longest mountain by combining LIS and LDS
        int maxMountain = 0;
        for (int i = 1; i < n - 1; i++) {
            if (lis[i] > 1 && lds[i] > 1) { // Valid peak
                maxMountain = max(maxMountain, lis[i] + lds[i] - 1);
            }
        }
        
        // Step 4: Minimum removals to get the longest mountain
        return n - maxMountain;
    }
};

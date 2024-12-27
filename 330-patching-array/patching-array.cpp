class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long long miss = 1; // The smallest number not yet representable
        int patches = 0, i = 0;

        while (miss <= n) {
            // If the current number in nums can extend the range
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i]; // Extend the range
                i++;
            } else {
                // Add `miss` as a patch
                miss += miss;
                patches++;
            }
        }

        return patches;
    }
};

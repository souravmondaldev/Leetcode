class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        int mod = 1e9 + 7;
        
        // Compute prefix sum of size n
        vector<long long> prefixSum(n, 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        
        // Find previous smaller and next smaller elements
        vector<int> previousSmall(n, -1), nextSmall(n, n);
        stack<int> monotonicInc;
        
        // Previous smaller element
        for (int i = 0; i < n; i++) {
            while (!monotonicInc.empty() && nums[monotonicInc.top()] >= nums[i]) {
                monotonicInc.pop();
            }
            if (!monotonicInc.empty()) previousSmall[i] = monotonicInc.top();
            monotonicInc.push(i);
        }
        
        // Clear the stack for the next pass
        while (!monotonicInc.empty()) monotonicInc.pop();
        
        // Next smaller element
        for (int i = n - 1; i >= 0; i--) {
            while (!monotonicInc.empty() && nums[monotonicInc.top()] >= nums[i]) {
                monotonicInc.pop();
            }
            if (!monotonicInc.empty()) nextSmall[i] = monotonicInc.top();
            monotonicInc.push(i);
        }
        
        // Compute the maximum min-product
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long leftBound = previousSmall[i] + 1;
            long long rightBound = nextSmall[i] - 1;
            long long currSum = prefixSum[rightBound] - (leftBound > 0 ? prefixSum[leftBound - 1] : 0);
            ans = max(ans, currSum * nums[i]);
        }
        
        return ans % mod;
    }
};

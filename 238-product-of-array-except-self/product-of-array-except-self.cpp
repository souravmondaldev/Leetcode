class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftProduct(n + 1, 1), rightProduct(n + 1, 1), ans(n, 0);
        for(int i = 0; i < n; i ++){
            leftProduct[i + 1] = leftProduct[i] * nums[i];
            rightProduct[n - i - 1] = rightProduct[n - i] * nums[n - i - 1];
        }

        for(int i = 0; i < n; i ++){
            ans[i] = leftProduct[i] * rightProduct[i + 1];
        }
        return ans;
    }
};
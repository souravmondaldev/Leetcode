class NumArray {
public:
    vector<int> prefixSum;
    void calculatePrefixSumArray(vector<int>&nums, vector<int>&prefixSum){
        int sum = 0;
        for(int i = 0; i < nums.size(); i ++){
            sum = sum + nums[i];
            prefixSum[i + 1] = sum ;
        }
    }
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n + 1, 0);
        calculatePrefixSumArray(nums, prefixSum);
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
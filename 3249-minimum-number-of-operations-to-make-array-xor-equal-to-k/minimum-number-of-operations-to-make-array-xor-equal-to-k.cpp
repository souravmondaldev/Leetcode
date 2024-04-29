class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int finalXor = 0;
        for(int num : nums){
            finalXor ^= num;
        }
        return __builtin_popcount(finalXor ^ k);
    }
};
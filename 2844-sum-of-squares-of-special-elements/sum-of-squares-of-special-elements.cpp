class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sumOfSquare = 0;
        for(int i = 0; i < n; i ++){
            sumOfSquare += n % (i + 1) == 0 ? pow(nums[i], 2) : 0;
        }

        return sumOfSquare;
    }
};
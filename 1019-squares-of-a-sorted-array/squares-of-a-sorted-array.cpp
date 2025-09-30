class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int left = 0, right = n - 1;
        int idx = n - 1;
        while(left <= right){
            int square = 0;
            if(abs(nums[left]) > abs(nums[right])){
                square = nums[left] * nums[left];
                left ++;
            }
            else {
                square = nums[right] * nums[right];
                right --;
            }
            // cout << square << " " << left << " " << right <<endl; 
            ans[idx] = square;
            idx --;
        }
        return ans;
    }
};
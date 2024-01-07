class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count  = 0;
        int n = nums.size();
        for(int i = 0; i < n - 2; i ++){
            int d = nums[i + 1] - nums[i];
            for(int j = i + 2;  j < n; j ++){
                if(nums[j] - nums[j - 1] == d)
                    count ++;
                else break;
            }
        }
        return count;
    }
};
class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int maxLen = -1;
        int currMaxLen = 0;
        for(int i = 0; i < nums.size() - 1; i ++){
            bool flag = false;
            for(int j = i + 1; j < nums.size(); j ++){
                if(!flag){
                    if(nums[j] - nums[j-1] == 1){
                        flag = true;
                        maxLen = max(maxLen, j - i + 1);
                    }
                    else {
                        break;
                    }
                }
                else {
                    if(nums[j] - nums[j-1] == -1){
                        flag = false;
                        maxLen = max(maxLen, j - i + 1);
                    }
                    else{
                        break;
                    }
                }
            }
            
        }
        return maxLen;
    }
};
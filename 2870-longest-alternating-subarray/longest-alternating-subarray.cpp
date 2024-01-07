class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int maxLen = -1;
        int n = nums.size(), i = 0, j = 1;
        bool ch = false;
        while(j < n){
            if(!ch){
                if(nums[j] - nums[j - 1] == 1){
                    ch = true;
                    maxLen = max(maxLen, j - i + 1);
                }
                else {
                    i = j;
                    }
                }
                else {
                    if(nums[j] - nums[j - 1] == -1){
                        ch = false;
                        maxLen = max(maxLen, j - i + 1);
                    }
                    else if(nums[j] - nums[j - 1] == 1){
                        i = j - 1;
                        maxLen = max(maxLen, j - i + 1);
                    }
                    else {
                        ch = false;
                        i = j;
                    }
                }
                j ++;
        }
        // Time(O(n2))
        // for(int i = 0; i < nums.size() - 1; i ++){
        //     bool flag = false;
        //     for(int j = i + 1; j < nums.size(); j ++){
        //         if(!flag){
        //             if(nums[j] - nums[j-1] == 1){
        //                 flag = true;
        //                 maxLen = max(maxLen, j - i + 1);
        //             }
        //             else {
        //                 break;
        //             }
        //         }
        //         else {
        //             if(nums[j] - nums[j-1] == -1){
        //                 flag = false;
        //                 maxLen = max(maxLen, j - i + 1);
        //             }
        //             else{
        //                 break;
        //             }
        //         }
        //     }
            
        // }
        return maxLen;
    }
};
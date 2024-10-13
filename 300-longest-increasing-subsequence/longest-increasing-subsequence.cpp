class Solution {
public:
    //O(N2) O(N)
    int lengthOfLISDp(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i ++){
            for(int j = 0; j < i; j ++){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
    //O(N2) O(N)
    int lengthOfLISDpOptimal(vector<int>& nums){
        vector<int> minNumsList;
        minNumsList.push_back(nums[0]);
        int idx = 1, n = nums.size();
        while(idx < n){
            if(nums[idx] > minNumsList[minNumsList.size() - 1]){
                minNumsList.push_back(nums[idx]);
            }
            else {
                int j = 0;
                while(j < minNumsList.size() && minNumsList[j] < nums[idx]){
                    j ++;
                }
                minNumsList[j] = nums[idx];
            }
            idx ++;
        }
        return minNumsList.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        // return lengthOfLISDp(nums);
        return lengthOfLISDpOptimal(nums);
    }
};
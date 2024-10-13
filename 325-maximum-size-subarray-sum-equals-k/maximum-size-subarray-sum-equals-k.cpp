class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<long, int> mp;
        long prefixSum = 0;
        int maxSubArraySize = INT_MIN;
        for(int i = 0; i < nums.size(); i ++){
            prefixSum += nums[i];
            if(prefixSum == k){
                maxSubArraySize = max(maxSubArraySize, i + 1);
            }
            long required = prefixSum - k;
            if(mp.find(required) != mp.end()){
                maxSubArraySize = max(maxSubArraySize, i - mp[required]);
            }
            if(mp.find(prefixSum) == mp.end()){
                mp[prefixSum] = i;
            }
        }

        return maxSubArraySize == INT_MIN ? 0 : maxSubArraySize;
        // {-2, 0} {-1, }
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumMap;
        sumMap[0] = 1;
        int count = 0;
        int currSum = 0;
        for(int i = 0; i < nums.size(); i ++){
            currSum += nums[i];
            int need = currSum - k;
            if(sumMap.find(need) != sumMap.end()){
                count += sumMap[need];
            }
            sumMap[currSum] ++;
        }
        return count;
    }
};
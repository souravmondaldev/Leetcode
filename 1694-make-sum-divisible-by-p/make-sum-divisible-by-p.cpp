class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int sumOfAll = 0;
        for(int i = 0; i < nums.size(); i ++){
            sumOfAll = (sumOfAll + nums[i]) % p;
        }
        //check if total array sum divisble by p, return 0
        int target = sumOfAll % p;
        if(target == 0)
            return 0;
        
        unordered_map<int, int> modMap;
        modMap[0] = -1; //To handle case where whole prefix is the number

        int currSum = 0, minLen = nums.size();
        for(int i = 0; i < nums.size(); i ++){
            currSum = (currSum + nums[i])%p;
            int need = (currSum- target + p) % p;

            if(modMap.find(need) != modMap.end()){
                minLen = min(minLen, i - modMap[need]);
            }
            modMap[currSum] = i;
        }

        return minLen == nums.size() ? -1 : minLen;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> numsStore;
        for(int i = 0; i < nums.size(); i ++){
            int complement = target - nums[i];
            if(numsStore.find(complement) != numsStore.end()){
                return {i, numsStore[complement]};
            }
            numsStore[nums[i]] = i;
        }

        return {-1, -1};
    }
};
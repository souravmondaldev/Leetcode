class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> numSet(nums.begin(), nums.end());
        return numSet.size() < nums.size();
    }
};
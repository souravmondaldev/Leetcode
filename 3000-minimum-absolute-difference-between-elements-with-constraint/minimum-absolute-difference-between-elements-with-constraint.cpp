class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> elements;
        int n = nums.size();
    
        int minDiff = INT_MAX;
        for(int i = x; i < n; i ++){
            elements.insert(nums[i - x]);
            auto it = elements.lower_bound(nums[i]);
            if(it != elements.end())
                minDiff = min(minDiff, abs(nums[i] - *it));
            if(it != elements.begin())
                minDiff = min(minDiff, abs(nums[i] - *prev(it))); 
        }
        return minDiff;
    }
};
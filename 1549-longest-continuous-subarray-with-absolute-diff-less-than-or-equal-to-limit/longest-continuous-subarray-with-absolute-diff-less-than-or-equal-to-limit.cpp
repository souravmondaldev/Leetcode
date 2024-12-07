class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> window;
        int left = 0, maxLen = 0;
        for(int right = 0 ; right < nums.size(); right ++){
            window.insert(nums[right]);
            while(*window.rbegin() - *window.begin() > limit){
                window.erase(window.find(nums[left]));
                left ++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};
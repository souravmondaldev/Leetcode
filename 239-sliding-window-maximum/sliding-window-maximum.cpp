class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;
        int left = 0, n = nums.size();
        vector<int> maxElementOverRollingKWindow;
        for(int right = 0; right < n; right ++){
            window.insert(nums[right]);
            if(window.size() == k){
                maxElementOverRollingKWindow.push_back(*window.rbegin());
                window.erase(window.find(nums[left]));
                left ++;
            }
        }

        return maxElementOverRollingKWindow;
    }
};
class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        int minRemaining = n - k;
        deque<int> monotonicInc;
        vector<int> ans;
        for(int i = 0;  i < n; i ++){
            while(!monotonicInc.empty() && monotonicInc.back() > nums[i] &&
                minRemaining > 0){
                monotonicInc.pop_back();
                minRemaining --;
            }
            monotonicInc.push_back(nums[i]);
        }
        for(int i = 0; i < k; i ++){
            ans.push_back(monotonicInc.front());
            monotonicInc.pop_front();
        }
        return ans;
    }
};
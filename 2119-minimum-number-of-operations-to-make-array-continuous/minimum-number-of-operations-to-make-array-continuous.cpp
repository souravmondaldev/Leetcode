class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        set<int> unique(nums.begin(), nums.end());
        vector<int> orderedNums;
        for(int num : unique){
            orderedNums.push_back(num);
        }
        int right = 0;
        for(int left = 0 ; left < orderedNums.size(); left ++){
            while(right < orderedNums.size() && orderedNums[right] < orderedNums[left] + n){
                right ++;
            }
            int count = right - left;
            ans = min(ans, n - count);
        }
        return ans;
    }
};
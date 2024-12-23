class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        unordered_map<int, int> freq;
        vector<int> ans;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int num: nums[i]){
                freq[num] ++;
            }
        }
        for(auto &[num, count] : freq){
            if(count == n){
                ans.push_back(num);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
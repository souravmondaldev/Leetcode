class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int ans = INT_MAX, maxRem = INT_MIN;
        unordered_map<int, int> remFreq;
        for(int num : nums){
            remFreq[num % space] ++;
            if(remFreq[num % space] > maxRem){
                maxRem = remFreq[num % space];
            }
        }
        for(int num : nums){
            if(remFreq[num % space] == maxRem){
                ans = min(ans, num);
            }
        }
        return ans;
    }
};
class Solution {
public:
    long long solve(vector<int>&power, unordered_map<int, int> &freq, int idx, vector<long long> &dp){
        if(idx >= power.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        long long take = 0, notTake = 0;
        int nextIdx = INT_MAX;
        for(int i = idx + 1; i < power.size(); i ++){
            if(power[i] - power[idx] > 2){
                nextIdx = i;
                break;
            }
        }
        take = power[idx]*1LL*freq[power[idx]]*1LL + solve(power, freq, nextIdx, dp);
        notTake = solve(power, freq, idx + 1, dp);
        return dp[idx] = max(take, notTake);
    }
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> freq;
        for(int p : power){
            freq[p] ++;
        }
        vector<int> unique_power;
        for(auto item : freq){
            unique_power.push_back(item.first);
        }
        sort(unique_power.begin(), unique_power.end());
        vector<long long> dp(unique_power.size() , -1);
        return solve(unique_power, freq, 0, dp);
    }
};
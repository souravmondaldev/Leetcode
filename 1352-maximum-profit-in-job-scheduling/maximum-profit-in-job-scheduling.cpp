class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobs;
        map<int, int> dp = {{0, 0}};
        for(int i = 0; i < n; i ++){
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        for(auto job : jobs){
            int curr = prev(dp.upper_bound(job[1]))->second + job[2];
            if(curr > dp.rbegin()-> second)
                dp[job[0]] = curr;
        }
        return dp.rbegin()->second;
    }
};
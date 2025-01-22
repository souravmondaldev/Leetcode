class Solution {
public:
    int solve(vector<int>&arr, map<pair<int, int>, int> &maxi, vector<vector<int>>&dp, int start,  int end){
        if(start == end)
            return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int ans = INT_MAX;
        for(int i = start; i < end; i ++){
            ans = min(ans, 
            maxi[{start, i}] * maxi[{i + 1, end}]
            + solve(arr, maxi, dp, start,  i)
            + solve(arr, maxi, dp, i + 1,  end));
        }
        return dp[start][end] = ans;
    }
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        map<pair<int, int>, int> maxi;
        for(int i = 0; i < n; i ++){
            maxi[{i, i}] = arr[i];
            for(int j = i + 1; j < n; j ++){
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }
        return solve(arr, maxi, dp, 0,  n - 1);
    }
};
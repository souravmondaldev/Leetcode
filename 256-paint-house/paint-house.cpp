class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        vector<vector<int>> memo(costs.size(), vector<int>(3, -1));
        return min(recur(costs, 0, 0, memo), 
                   min(recur(costs, 0, 1, memo), 
                       recur(costs, 0, 2, memo)));
    }

private:
    int recur(vector<vector<int>>& costs, int idx, int color, vector<vector<int>>& memo) {
        if (idx == costs.size()) return 0;
        if (memo[idx][color] != -1) return memo[idx][color];
        int minCost = INT_MAX;
        for (int nextColor = 0; nextColor < 3; nextColor++) {
            if (nextColor != color) { 
                minCost = min(minCost, recur(costs, idx + 1, nextColor, memo));
            }
        }
        return memo[idx][color] = costs[idx][color] + minCost;
    }
};

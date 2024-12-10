class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty()) return 0;

        int n = costs.size();
        int k = costs[0].size();
        vector<vector<int>> memo(n, vector<int>(k, -1));

        int minCost = INT_MAX;

        // Try all colors for the first house
        for (int color = 0; color < k; color++) {
            minCost = min(minCost, recur(costs, 0, color, memo));
        }

        return minCost;
    }

private:
    int recur(vector<vector<int>>& costs, int house, int prevColor, vector<vector<int>>& memo) {
        if (house == costs.size()) return 0;

        if (memo[house][prevColor] != -1) return memo[house][prevColor];

        int minCost = INT_MAX;

        for (int color = 0; color < costs[0].size(); color++) {
            if (color != prevColor) { // Avoid same color as the previous house
                int currCost = costs[house][color] + recur(costs, house + 1, color, memo);
                minCost = min(minCost, currCost);
            }
        }

        return memo[house][prevColor] = minCost;
    }
};

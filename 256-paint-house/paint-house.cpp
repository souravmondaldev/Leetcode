class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        // if (costs.empty()) return 0;
        // vector<vector<int>> memo(costs.size(), vector<int>(3, -1));
        // return min(recur(costs, 0, 0, memo), 
        //            min(recur(costs, 0, 1, memo), 
        //                recur(costs, 0, 2, memo)));
        int prevRed = costs[0][0], prevBlue = costs[0][1], prevGreen = costs[0][2];
        int currRed = 0, currBlue = 0, currGreen = 0;
        for(int i = 1; i < costs.size(); i ++){
            currRed = costs[i][0] + min(prevBlue, prevGreen);
            currBlue = costs[i][1] + min(prevRed, prevGreen);
            currGreen = costs[i][2] + min(prevBlue, prevRed);
            prevRed = currRed;
            prevBlue = currBlue;
            prevGreen = currGreen;
        }
        return min(prevGreen, min(prevBlue, prevRed));
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

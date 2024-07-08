class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> memo(cost.size() + 1, -1);
        return minCost(cost.size(), cost, memo);
    } 
    int minCost(int i, vector<int>& cost, vector<int> &memo){
        if(i <= 1)
            return 0;
        if(memo[i] != -1)
            return memo[i];
        return memo[i] = min(cost[i - 1] + minCost(i - 1, cost, memo),
                            cost[i - 2] + minCost(i - 2, cost, memo));
    }
    
};
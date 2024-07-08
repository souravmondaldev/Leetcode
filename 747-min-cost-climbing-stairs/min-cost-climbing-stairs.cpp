class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // vector<int> memo(cost.size() + 1, -1);
        // return minCost(cost.size(), cost, memo);
        int downOne = 0, downTwo = 0;
        for(int i = 2; i <= cost.size(); i ++){
            int temp = downOne;
            downOne = min(downOne + cost[i - 1], downTwo + cost[i - 2]);
            downTwo = temp;
        }
        return downOne;
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
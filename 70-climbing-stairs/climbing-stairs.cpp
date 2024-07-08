class Solution {
public:
    int climbStairs(int n) {
        int wayToReachLastStep = 2, waysToReachSecondLast = 1, numOfWays = n;
        for(int i = 3; i <= n; i ++){
            numOfWays = wayToReachLastStep + waysToReachSecondLast;
            waysToReachSecondLast = wayToReachLastStep;
            wayToReachLastStep = numOfWays;
        }
        return numOfWays;
    }
};
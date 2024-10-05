class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;
        int first = 1, second = 2, curr = 0;
        for(int i = 3; i <= n; i ++){
            curr = first + second;
            first = second;
            second = curr;
        }
        return curr;
    }
};
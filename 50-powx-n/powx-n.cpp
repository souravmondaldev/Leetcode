class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        // return n > 0 ? x * myPow(x, n - 1) : 1/ (x * myPow(x, -n -1));
        if(n < 0){
            n = (long long)-1 * n;
            x = 1.0/x;
        }
        double result = 1;
        while(n){
            if(n&1){
                result = result * x;
            }
            x = x * x;
            n = n / 2;
        }
        return result;
    }
};
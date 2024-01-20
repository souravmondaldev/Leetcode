class Solution {
private:
    int MOD = 1000000007;
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> stack;
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i ++){
            while(!stack.empty() && arr[stack.top()] >= arr[i]){
                stack.pop();
            }
            if(stack.size() > 0){
                int previousSmall = stack.top();
                dp[i] = dp[previousSmall] + (i - previousSmall) * arr[i];
            }
            else{
                dp[i] = (i + 1) * arr[i];
            }
            stack.push(i);
        }
        long sumOfMins = 0;
        for(int num : dp){
            sumOfMins += num;
            sumOfMins %= MOD;
        }

        return sumOfMins;
    }
};
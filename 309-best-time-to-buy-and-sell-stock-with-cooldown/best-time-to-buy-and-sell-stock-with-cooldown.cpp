class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN, sold = INT_MIN, reset = 0;
        for(int price : prices){
            int preSold = sold;
            sold = buy + price;
            buy = max(buy, reset - price);
            reset = max(reset, preSold);
        }
        return max(sold, reset);
        // int n = prices.size();
        // if(n == 0)
        //     return 0;
        // vector<int> hold(n + 1, 0);
        // vector<int> nonHold(n + 1, 0);
        // hold[1] -= prices[0];
        // nonHold[1] = 0;
        // for(int i = 1; i < n; i ++){
        //     hold[i + 1] = max(hold[i], nonHold[i - 1] - prices[i]);
        //     nonHold[i + 1] = max
        // }
    }
    
};
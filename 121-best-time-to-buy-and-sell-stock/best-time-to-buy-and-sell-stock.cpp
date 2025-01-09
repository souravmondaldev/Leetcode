class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxProfit = INT_MIN, minBuy = INT_MAX;
       for(int price : prices){
            minBuy = min(minBuy, price);
            maxProfit = max(maxProfit, price-minBuy);
       }
        return maxProfit;
    }
};
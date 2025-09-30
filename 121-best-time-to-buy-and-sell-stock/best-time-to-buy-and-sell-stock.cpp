class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(prices.size() == 0 || prices.size() == 1)
            return 0; 
        //Let's store the status in an 2D array
        //[i][0] -> 0 representing the cheapest from [1 to i] to buy a stock 
        //[i][1] -> representing the highest value possible by selling the stock 

        // vector<vector<int>> DP(prices.size(), vector<int>(2, 0));
        // DP[0][0] = prices[0];
        // DP[0][1] = 0; //max profit till now
        // for(int i=1; i< prices.size(); ++i){
        //     //If we want to buy the stock today then or check if it's cheaper to use a previous day minimum
        //     DP[i][0] = min(prices[i], DP[i-1][0]);
        //     DP[i][1] = max(prices[i] - DP[i][0], DP[i-1][1]);
        // }

        // return DP[size-1][1];
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;
        for(int price : prices){
            minPrice = min(price, minPrice);
            maxProfit = max(maxProfit, price - minPrice);
            // cout << minPrice << " : " << price << " : " << maxProfit << endl;
        }
        return maxProfit;
    }
};
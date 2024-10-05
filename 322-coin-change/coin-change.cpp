class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        queue<pair<int, int>> q;
        unordered_set<int> seen;
        q.push({amount, 0});
        while(!q.empty()){
            int sz = q.size();
            // while(sz){
                pair<int, int> top = q.front();
                q.pop();
                int currAmount = top.first;
                int count = top.second;
                if(currAmount == 0)
                    return count;
                count ++;
                for(int i = 0; i < coins.size(); i ++){
                    int remaining = currAmount - coins[i];
                    if(seen.count(remaining) == 0 && remaining >= 0){
                        seen.insert(remaining);
                        q.push({currAmount - coins[i], count});
                    }
                    
                }
                sz --;
            // }
            
        }
        return -1;
    }
    // int coinChangeDp(int amount, vector<int> &coins, vector<int>&dp, int count){
    //     if(amount <= 0)
    //         return;
    //     if(dp[amount] != -1)
    //         return dp[amount];
    //     for(int i = 0; i < coins.size(); i ++){
            
    //     }
    // }
};
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& times) {
        vector<int> remainders(60, 0);
        int ans = 0;
        for(int time : times){
            int remainder = 60 - time % 60;
            if(time % 60 == 0) ans += remainders[0];
            else ans += remainders[remainder];
            remainders[time % 60] ++;
        }
        return ans;
    }
};
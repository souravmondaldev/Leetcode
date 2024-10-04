class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
        int n = skills.size();
        int sumOfTwoPlayer = INT_MIN;
        long long chemistry = 0;
        sort(skills.begin(), skills.end());

        for(int i = 0; i < n/2; i ++){
            int currSum = skills[i] + skills[n - i - 1];
            if(sumOfTwoPlayer == INT_MIN)
                sumOfTwoPlayer = currSum;
            
            if(sumOfTwoPlayer != currSum)
                return -1;
            
            chemistry += skills[i] * skills[n - i - 1];
        }
        return chemistry;
    }
};
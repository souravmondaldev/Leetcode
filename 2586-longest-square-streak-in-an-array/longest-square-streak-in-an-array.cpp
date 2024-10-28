class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int> numStore(nums.begin(), nums.end());
        int maxNum = pow(INT_MAX, 0.5);
        int longestStreak = 1, currentStreak = 0;
        for(int num : nums){
            int currentNum = num;
            while(numStore.count(currentNum)){
                currentStreak ++;
                currentNum = currentNum > maxNum ? -1 : currentNum * currentNum;
            }
            longestStreak = max(longestStreak, currentStreak);
            currentStreak = 0;
        }
        return longestStreak > 1 ? longestStreak : -1;
    }
};
class Solution {
public:
    // long long dividePlayers(vector<int>& skills) {
    //     int n = skills.size();
    //     int sumOfTwoPlayer = INT_MIN;
    //     long long chemistry = 0;
    //     sort(skills.begin(), skills.end());

    //     for(int i = 0; i < n/2; i ++){
    //         int currSum = skills[i] + skills[n - i - 1];
    //         if(sumOfTwoPlayer == INT_MIN)
    //             sumOfTwoPlayer = currSum;
            
    //         if(sumOfTwoPlayer != currSum)
    //             return -1;
            
    //         chemistry += skills[i] * skills[n - i - 1];
    //     }
    //     return chemistry;
    // }
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        vector<int> freq(1002, 0);
        long long chemistry = 0;
        int sumOfAll = 0;
        for(int i = 0; i < n; i ++){
            freq[skill[i]] ++;
            sumOfAll += skill[i];
        }

        if(sumOfAll % (n / 2) != 0)
            return -1;
        int sumOfTwo = sumOfAll / (n / 2);

        for(int i = 0; i < n; i ++){
            int currNum = skill[i];
            int target = sumOfTwo - currNum;
            if(freq[target] > 0){
                chemistry += (long long)currNum * (long long)target;
                freq[target] --;
            }
            else return -1;
        }
        return chemistry/2;
    }

};
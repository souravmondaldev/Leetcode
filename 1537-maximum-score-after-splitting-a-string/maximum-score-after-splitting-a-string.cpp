class Solution {
public:
    int maxScore(string s) {
        int totalOnes = 0;
        for(int i = 0; i < s.length(); i ++){
            totalOnes += s[i] == '1' ? 1 : 0;
        }
        int maxScore = 0;
        int prevZero = 0, prevOne = 0;
        for(int i = 0; i < s.length() - 1; i ++){
            prevZero += s[i] == '0' ? 1 : 0;
            if(s[i] == '1') totalOnes --;
            int currentScore = (prevZero + totalOnes);
            maxScore = max(maxScore, currentScore);
        }
        return maxScore;
    }
};
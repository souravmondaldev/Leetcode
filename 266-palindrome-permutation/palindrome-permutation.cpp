class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> freq(26, 0);
        for(char ch : s){
            freq[ch - 'a'] ++;
        }
        int oddFreq = 0;
        for(int i = 0; i < 26; i ++){
            if(freq[i] & 1) oddFreq ++;
        }
        return oddFreq <= 1;
    }
};
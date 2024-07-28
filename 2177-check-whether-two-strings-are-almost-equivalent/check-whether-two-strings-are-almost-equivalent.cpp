class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        vector<int> charCount(26, 0);
        for(int i = 0; i < word1.size(); i ++){
            charCount[word1[i] - 'a'] ++;
            charCount[word2[i] - 'a'] --;
        }
        for(int i = 0; i < 26; i ++){
            if(abs(charCount[i]) > 3)
                return false;
        }
        return true;
    }
};
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length() != word2.length())
            return false;
        int word1Count[26] = {0};
        int word2Count[26] = {0};
        for(int i = 0; i < word1.length(); i ++){
            word1Count[word1[i] - 'a'] ++;
        }
        for(int i = 0; i < word1.length(); i ++){
            word2Count[word2[i] - 'a'] ++;
            if(word1Count[word2[i] - 'a'] == 0)
                return false;
        }
        sort(word1Count, word1Count + 26);
        sort(word2Count, word2Count + 26);
        for(int i = 0; i < 26; i ++){
            if(word1Count[i] != word2Count[i])
                return false;
        }

        return true;
    }
};
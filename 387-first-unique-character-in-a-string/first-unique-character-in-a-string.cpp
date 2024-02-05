class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> char_freq(26, 0);
        for(char ch : s)
            char_freq[ch - 'a'] ++;
        int idx = 0;
        for(char ch : s){
            if(char_freq[ch - 'a'] == 1)
                return idx;
            idx ++;
        }

        return -1;
    }
};
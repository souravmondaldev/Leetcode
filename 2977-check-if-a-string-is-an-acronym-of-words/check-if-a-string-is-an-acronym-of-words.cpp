class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        int i = 0;
        int n = words.size(), m = s.length();
        if(n != m) return false;
        bool acronym = true;
        while(i < n){
            if(words[i][0] != s[i])
                return false;
            i ++;
        }

        return acronym;
    }
};
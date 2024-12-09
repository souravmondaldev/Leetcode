class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        map<string, bool> mp;
        for(string word : words){
            if(mp.find(word) != mp.end()){
                if(mp[word] == true)
                    count ++;
                continue;
            }
            mp[word] = subseq(s, word);
            count += (mp[word] == true);
        }
        return count;
    }
    bool subseq(string s, string word){
        int idx = 0;
        for(char ch : s){
            if(idx < word.length() && word[idx] == ch)
                idx ++;
        }
        return idx == word.length();
    }
};
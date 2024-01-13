class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> freq;
        int minStep = 0;
        for(char ch: s)
            freq[ch] ++;
        for(char ch : t){
            if(freq.find(ch) != freq.end())
                freq[ch] --;
        }
        for(auto pair : freq){
            minStep += pair.second > 0 ? pair.second : 0;
        }

        return minStep;
    }
};
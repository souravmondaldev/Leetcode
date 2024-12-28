class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), i = 0, j = 0, maxElFreq = 0;
        unordered_map<char, int> mp;
        int ans = 0;
        for(int i = 0; i < n; i ++){
            mp[s[i]] ++;
            maxElFreq = max(maxElFreq, mp[s[i]]);
            if(i - j + 1 - maxElFreq > k){
                mp[s[j]] --;
                j ++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
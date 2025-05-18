class Solution {
public:
    bool isVowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> prefixSum(words.size() + 1, 0);
        for(int i = 0; i < words.size(); i ++){
            prefixSum[i + 1] = prefixSum[i] + (isVowel(words[i][0]) && isVowel(words[i].back()) ? 1 : 0);
        }

        for(auto query : queries){
            int l = query[0], r = query[1];
            ans.push_back(prefixSum[r + 1] -  prefixSum[l]);
        }
        return ans;
    }
};
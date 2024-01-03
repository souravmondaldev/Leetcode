class Solution {
public:
    // O(N*L) O(M)
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int n = word.length();
        unordered_map<string, int> mp;

        int len = 0;
        for(auto it: forbidden){
            mp[it] = 1;
            len = max(len, (int) it.size());
        }
        int right = n;
        int ans = 0;

        for(int i = n - 1; i >= 0; i --){
            string temp = "";
            for(int j = i; j < n and j < i + len and j <= right; j ++){
                temp += word[j];
                if(mp[temp] == 1){
                    right = j;
                    break;
                }
            }
            ans = max(ans, right - i);
        }
        return ans;
    }
};
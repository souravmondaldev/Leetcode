class Solution {
public:
// O(N) O(1)
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int n = s.length();
        if(n <= 2)
            return n;
        
        int left = 0, right = 0, max_len = 2;
        unordered_map<char, int> mp;
        while(right < n){
            mp[s[right]] = right;
            right ++;
            if(mp.size() == 3){
                int min_idx = INT_MAX;
                for(pair<char, int> el: mp){
                    min_idx = min(min_idx, el.second);
                }

                mp.erase(s[min_idx]);
                left = min_idx + 1;
            }
            max_len = max(max_len, right - left);
        }
        return max_len;
    }
};
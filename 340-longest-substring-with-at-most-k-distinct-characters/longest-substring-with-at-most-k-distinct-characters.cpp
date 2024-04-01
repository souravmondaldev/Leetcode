class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int n = s.length();
        if(n <= k)
            return n;
        if(k == 0)
            return k;
        int left = 0, right = 0, max_len = 0;
        unordered_map<char, int> mp;

        while(right < n){
            mp[s[right]] = right;
            right ++;
            if(mp.size() > k){
                int min_pos = INT_MAX;
                for(auto &[letter, pos]: mp){
                    // cout << letter << pos <<endl; 
                    min_pos = min(min_pos, pos);
                }
                mp.erase(s[min_pos]);
                left = min_pos + 1;
            }
            // cout << left << " : " << right << endl; 
            max_len = max(max_len, right - left);
        }
        return max_len;
    }
};
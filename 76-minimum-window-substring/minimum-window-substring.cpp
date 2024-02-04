class Solution {
public:
    /*
        Cases: 
        1. s null or empty return ""
        2. s does not contain t then return ""
        3. s does contains t then return the minmum length substr of s

        Analysis:
        s = "ABAACBCA", t = "ABC"
        Out of possible options "ABAAC", "BAAC" and "ACB", "ACB" will be the optimal answer.

        Approach:
        Sliding window

        Time Complexity:

        Space Complexity:

    */
    string minWindow(string s, string t) {
        vector<int> freq_t(126, 0);
        for(char ch: t)
            freq_t[ch] ++;

        int low = 0, minLen = INT_MAX, start = 0, count = 0;
        for(int high = 0; high < s.length(); high ++){
            if(freq_t[s[high]] > 0)
                count ++;
            freq_t[s[high]] --;
            if(count == t.length()){
                while(low < high && freq_t[s[low]] < 0){
                    freq_t[s[low]] ++;
                    low ++;
                }
                if(minLen > high - low + 1){
                    minLen = high - low + 1;
                    start = low;
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);

    }
};
/**
 * Definition for an infinite stream.
 * class InfiniteStream {
 * public:
 *     InfiniteStream(vector<int> bits);
 *     int next();
 * };
 */
class Solution {
public:
    vector<int> getLps(vector<int> &s){
        int n = s.size();
        vector<int> lps(n, 0);
        int len = 0, i = 1;
        while(i < n){
            if(s[i] == s[len]){
                len ++;
                lps[i] = len;
                i ++;
            }else{
                if(len == 0){
                    lps[i] = 0;
                    i ++;
                }
                else len = lps[len - 1];
            }
        }
        return lps;
    }
    int findPattern(InfiniteStream* stream, vector<int>& pattern) {
        vector<int> lps = getLps(pattern);
        int n = pattern.size();
        int i = 0, res = 0;
        while(i < n){
            int ch  = stream->next();
            res ++;
            while(i > 0 && ch != pattern[i]){
                i = lps[i - 1];
            }
            if(ch == pattern[i]){
                i ++;
                if(i == n){
                    return res - n;
                }
            }
        }
        return -1;
    }
};
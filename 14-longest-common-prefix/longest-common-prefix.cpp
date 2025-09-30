class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minStrLen = INT_MAX;

        for(string str : strs){
            int len = str.length();
            minStrLen = min(minStrLen, len);
        }
        int idx = 0;
        while(idx < minStrLen){
            // char prevChar = '#';
            bool invalid = false;
            char curr = strs[0][idx];
            for(string str : strs){
                if(str[idx] != curr){
                   invalid = true;
                    break;
                }
            }
            if(invalid) break;
            idx ++;
        }
        return strs[0].substr(0, idx);

    }
};
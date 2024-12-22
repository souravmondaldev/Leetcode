class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;
        int n = word.size();
        for(string pattern : patterns){
            bool matchFound = false;
            for(int i = 0; i < n; i ++){
                string str = "";
                for(int j = i; j < n; j ++){
                    str += word[j];
                    if(str == pattern){
                        matchFound = true;
                        break;
                    }
                }
                if(matchFound) break;
            }
            if(matchFound) count ++;
        }
        return count;
    }
};
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length(), count = 0;
        int soFarNoWords = false;
        for(int i = n - 1; i >= 0; i --){
            if(s[i] == ' ' && soFarNoWords) break;
                soFarNoWords = false;
            if(s[i] != ' '){
                soFarNoWords = true;
                count ++;
            }
        }
        return count;
    }
};
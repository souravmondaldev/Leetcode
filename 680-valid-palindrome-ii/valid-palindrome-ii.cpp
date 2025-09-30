class Solution {
public:
    bool checkPalindrome(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j])
                return false;
            i ++;
            j --;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        while(left < right){
            if(s[left] != s[right]){
                return (checkPalindrome(s, left, right - 1) || checkPalindrome(s, left+1, right));
            }
            left ++;
            right --;
        }
        return true;
    }
};
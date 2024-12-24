class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n == 1) return s;
        string longestPalindromeStr = "";
        for(int i = 0; i < n; i ++){
            string odd = expand(s, i , i);
            string even =  expand(s, i - 1, i);
            string currLongestPalindromeStr = odd.length() > even.length() ? odd : even;

            longestPalindromeStr = longestPalindromeStr.length() > currLongestPalindromeStr.length() ?
                longestPalindromeStr : currLongestPalindromeStr;
        }

        return longestPalindromeStr;
    }
    string expand(string s, int start , int end){
        while(start >= 0 && end < s.length() && s[start] == s[end]){
            start --;
            end ++;
        }
        return s.substr(start + 1, end - start - 1);
    }
};
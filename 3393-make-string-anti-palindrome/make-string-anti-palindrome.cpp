class Solution {
public:
    string makeAntiPalindrome(string s) {
        string antipattern = "";
        vector<int> freq(26, 0);
        int maxFreq = s.length() / 2;
        
        // Calculate frequency of each character in the string
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        
        // Construct the antipattern
        for (int i = 0; i < s.length(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                // Check the conditions to avoid duplicate characters in the same position
                if (freq[c - 'a'] > 0 && (i < maxFreq || (antipattern.length() > 0 && antipattern[s.length() - i - 1] != c))) {
                    freq[c - 'a']--;
                    antipattern += c;
                    break;
                }
            }
            
            // If no valid character is found, return -1
            if (antipattern.length() != i + 1) {
                return "-1";
            }
        }
        
        return antipattern;
    }
};

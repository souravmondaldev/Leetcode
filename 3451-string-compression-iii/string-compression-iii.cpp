class Solution {
public:
    string compressedString(string word) {
        int pos = 0;
        string compressed = "";
        while(pos < word.length()){
            int count = 0;
            char currentChar = word[pos];
            while(pos < word.length() && count < 9 && word[pos] == currentChar){
                pos ++;
                count ++;
            }
            compressed += to_string(count) + currentChar;
        }
        return compressed;
    }
};
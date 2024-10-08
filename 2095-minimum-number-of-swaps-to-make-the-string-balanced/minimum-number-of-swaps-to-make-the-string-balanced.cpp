class Solution {
public:
    int minSwaps(string s) {
        stack<char> chars;
        for(char ch: s){
            if(ch == '['){
                chars.push(ch);
            }
            else {
                if(chars.size() > 0)
                    chars.pop();
            }
        }
        return (chars.size()  + 1)/2;
    }
};
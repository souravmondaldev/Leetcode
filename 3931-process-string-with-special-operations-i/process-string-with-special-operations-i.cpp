class Solution {
public:
    string processStr(string s) {
        string result = "";
        for(char ch : s){
            if(ch >= 'a' && ch <= 'z'){
                result += ch;
            }
            else if(ch == '*' && result.size()){
                result = result.substr(0, result.size() - 1);
            }
            else if(ch == '#'){
                result += result;
            }
            else if(ch == '%'){
                reverse(result.begin(), result.end());
            }
        }
        return result;
    }
};
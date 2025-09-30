class Solution {
public:
    bool isValid(string s) {
       vector<char> openingBrackets;
       unordered_set<char> closingBrackets = {')', '}', ']'};
       for(char bracket : s){
            if(closingBrackets.count(bracket)){
                if(openingBrackets.empty()) return false;
                char lastBracket = openingBrackets.back();
                if((lastBracket=='(' && bracket != ')') ||
                        (lastBracket=='{' && bracket != '}') ||
                        (lastBracket=='[' && bracket != ']')){
                            return false;
                        }   
                openingBrackets.pop_back();
            }
            else openingBrackets.push_back(bracket);
       }
       return openingBrackets.empty();
    }
};
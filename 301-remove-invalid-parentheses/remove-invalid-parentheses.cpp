class Solution {
public:
    unordered_map<string, int> seen;
    int getMinValid(string s){
        stack<char> st;
        int i = 0;
        while(i < s.length()){
            if(s[i] == '(')
                st.push('(');
            else if(s[i] == ')') {
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }
                else st.push(')');
            }
            i ++;
        }
        return st.size();
    }
    void backtrac(string s, vector<string>&ans, int minInvalid){
        if(seen[s]) return;
        else seen[s] ++;
        if(minInvalid == 0){
            if(getMinValid(s) == 0){
                ans.push_back(s);
                return;
            }
            return;
        }
        for(int i = 0; i < s.length(); i ++){
            string left = s.substr(0, i);
            string right = s.substr(i+1);
            backtrac(left+right, ans, minInvalid-1);
        }
        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        int minInvalid = getMinValid(s);
        vector<string> ans;
        backtrac(s, ans, minInvalid);
        return ans;
    }
};
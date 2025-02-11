class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans = "";
        int n = part.length();
        for(char ch : s){
            ans += ch;
            if(ans.size() >= n){
                string substr = ans.substr(ans.length()-n, n);
                cout << substr << endl;
                if(substr == part){
                    for(int i = 0; i < n; i ++){
                        ans.pop_back();
                    }
                }
                
            }
        }
        return ans;
    }
};
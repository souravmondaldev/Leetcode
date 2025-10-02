class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        unordered_map<char, int> mp1;
        unordered_set<char> mp2;
        for(int i = 0; i < s.length(); i ++)
            mp1[s[i]] ++;

        for(int i = 0; i < order.size(); i ++){
            if(mp1.find(order[i]) != mp1.end()){
                while(mp1[order[i]] > 0){
                    ans += order[i];
                    mp1[order[i]] --;
                }
                mp2.insert(order[i]);
            }
        }
        for(int i = 0; i < s.length(); i ++){
            if(mp2.find(s[i]) == mp2.end()){
                ans += s[i];
            }
        }

        return ans;
    }
};
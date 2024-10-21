class Solution {
private:
    unordered_set<string> seen;
    int dfs(int idx, string str){
        if(idx == str.length())
            return 0;
        int res = 0;
        for(int i = idx + 1; i <= str.length(); i ++){
            string substr = str.substr(idx, i - idx);
            if(seen.count(substr) != 0)
                continue;
            seen.insert(substr);
            res = max(res, 1 + dfs(i, str));
            seen.erase(substr);
        }
        return res;
    }
public:
    int maxUniqueSplit(string s) {
        return dfs(0, s);
    }
};
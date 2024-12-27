class Solution {
public:
    unordered_map<string, vector<string>> hashMap;
    string getHash(string str){
        string hash = "";
        for(int i = 1; i < str.length(); i ++){
            hash += (str[i]- str[i - 1]+26)%26 + 'a';
        }
        return hash;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        for(string str : strings){
            hashMap[getHash(str)].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto list : hashMap){
            ans.push_back(list.second);
        }
        return ans;
    }
};
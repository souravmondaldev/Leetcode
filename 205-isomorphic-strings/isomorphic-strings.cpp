class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sI[128] = {0}, tI[128] = {0};
        for(int i = 0; i < s.size(); i ++){
            if(sI[s[i]] != tI[t[i]])    return false;
            sI[s[i]] = i + 1;
            tI[t[i]] = i + 1;
        }
        return true;
    }
};
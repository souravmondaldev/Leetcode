class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n2 < n1)
            return false;
        sort(s1.begin(), s1.end());
        for(int i = 0; i <= n2 - n1; i ++){
            string s3 = s2.substr(i, n1);
            sort(s3.begin(), s3.end());
            if(s1 == s3)
                return true;
        }
        return false;
    }
};
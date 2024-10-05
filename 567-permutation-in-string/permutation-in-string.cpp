class Solution {
public:
    //O(n2-n1)n1logn1 //new string of size n1 and sortig takes logn1 n1+logn1
    // bool checkInclusion(string s1, string s2) {
    //     int n1 = s1.size(), n2 = s2.size();
    //     if(n2 < n1)
    //         return false;
    //     sort(s1.begin(), s1.end());
    //     for(int i = 0; i <= n2 - n1; i ++){
    //         string s3 = s2.substr(i, n1);
    //         sort(s3.begin(), s3.end());
    //         if(s1 == s3)
    //             return true;
    //     }
    //     return false;
    // }
    //O((n2-n1)*(n1+26) + n1) o(n2-n1) =~ O(1)
    bool ifPermutation(vector<int>&s1Map, vector<int>&s2Map){
        for(int i = 0; i < 26; i ++){
            if(s1Map[i] != s2Map[i])
                return false;
        }
        return true;
    }
    // bool checkInclusion(string s1, string s2) {
    //     int n1 = s1.size(), n2 = s2.size();
    //     if(n2 < n1)
    //         return false;
    //     vector<int> s1Map(26, 0);
    //     for(char ch: s1)
    //         s1Map[ch - 'a'] ++;
        
    //     for(int i = 0; i <= n2 - n1; i ++){
    //         vector<int> s2Map(26, 0);
    //         for(int j = i; j < i + n1; j ++){
    //             s2Map[s2[j] - 'a'] ++;
    //         }
    //         if(ifPermutation(s1Map, s2Map))
    //             return true;
    //     }
    //     return false;
    // }

    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        if(n2 < n1)
            return false;
        vector<int> s1Map(26, 0);
        vector<int> s2Map(26, 0);
        for(int i = 0; i < n1; i ++){
            s1Map[s1[i] - 'a'] ++;
            s2Map[s2[i] - 'a'] ++;
        }
        for(int i = 0; i < n2 - n1; i ++){
            if(ifPermutation(s1Map, s2Map))
                return true;
            s2Map[s2[i + n1] - 'a'] ++;
            s2Map[s2[i] - 'a'] --;
        }
        return ifPermutation(s1Map, s2Map);
    }

};
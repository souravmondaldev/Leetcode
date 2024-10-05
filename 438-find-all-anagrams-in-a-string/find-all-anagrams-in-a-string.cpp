class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1 = p.length(), n2 = s.length();
        vector<int> sMap(26, 0), pMap(26, 0), anagramIndex;
        if(n1 > n2)
            return anagramIndex;
        for(int i = 0; i < n1; i ++){
            sMap[s[i] - 'a'] ++;
            pMap[p[i] - 'a'] ++;
        }
        int matchingCount = 0;
        for(int i = 0; i < 26; i ++){
            if(sMap[i] == pMap[i])  
                matchingCount ++;
        }
        for(int i = 0; i < n2 - n1; i ++){
            if(matchingCount == 26){
                anagramIndex.push_back(i);
            }
            int idxToDesc = s[i] - 'a', idxToInc = s[i + n1] - 'a';
            
            sMap[idxToInc] ++;
            if(sMap[idxToInc] == pMap[idxToInc])
                matchingCount ++;
            else if(sMap[idxToInc] == pMap[idxToInc] + 1)
                matchingCount --;

            sMap[idxToDesc] --;
            if(sMap[idxToDesc] == pMap[idxToDesc])
                matchingCount ++;
            else if(sMap[idxToDesc] == pMap[idxToDesc] - 1)
                matchingCount --;
        }
        if(matchingCount == 26)
            anagramIndex.push_back(n2-n1);
        return anagramIndex;
    }
};
class Solution {
public:
    // time= > O(nlogn + mlogm) && space => o(logn + logm);
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        while(i < g.size() && j < s.size()){
            if(s[j] >= g[i])
                i ++;
            j ++;
        }

        return i;
    }
};
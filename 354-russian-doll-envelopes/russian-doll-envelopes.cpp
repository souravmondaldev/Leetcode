class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [&](vector<int>&a, vector<int>&b){
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        vector<int> increasingSeq;
        increasingSeq.push_back(envelopes[0][1]);
        int n = envelopes.size();
        int idx = 1;
        while(idx < n){
            if(envelopes[idx][1] > increasingSeq[increasingSeq.size() - 1]){
                increasingSeq.push_back(envelopes[idx][1]);
            }
            else{
                int j = lower_bound(increasingSeq.begin(),
                increasingSeq.end(), envelopes[idx][1]) - increasingSeq.begin();
                increasingSeq[j] = envelopes[idx][1];
            }
            idx ++;
        }
        return increasingSeq.size();

    }
};
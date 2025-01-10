class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> bloomOrder;
        bloomOrder[0] = 0;
        for(auto flower : flowers){
            int start = flower[0], end = flower[1] + 1;
            bloomOrder[start] ++;
            bloomOrder[end] --;
        }
        vector<int> pos, prefix;
        int curr = 0;
        int idx = 0;
        for(auto bloom : bloomOrder){
            pos.push_back(bloom.first);
            curr += bloom.second;
            prefix.push_back(curr);
            // cout << idx << " : " << pos[idx] << " : " << prefix[idx] <<endl;
            idx ++;
            
        }
        vector<int> ans;
        for(int person : people){
            int i = upper_bound(pos.begin(), pos.end(), person) - pos.begin() - 1;
            // cout << i << endl;
            ans.push_back(prefix[i]);
        }
        return ans;

    }
};
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void unionDsu(int u, int v){
        int parentU = find(u);
        int parentV = find(v);
        if(parentU != parentV){
            // if(rank[parentU] > rank[parentV])
            //     swap(parentU, parentV);
            parent[parentU] = parentV;
            // rank[parentV] += rank[parentU];
        }
    }
    int largestComponentSize(vector<int>& nums) {
        parent.resize(100005, 0);
        rank.resize(100005, 1);
        for(int i = 0; i < 100005; i ++){
            parent[i] = i;
        }
        for(int num : nums){
            for(int i = 2; i*i <= num; i ++){
                if(num % i == 0){
                    unionDsu(num, i);
                    unionDsu(num/i, i);
                }
            }
        }
        unordered_map<int, int> mp;
        for(int num : nums){
            mp[find(num)] ++;
        }
        int maxCount = 0;
        for(auto [num, count] : mp){
            maxCount = max(maxCount, count);
        }
        return maxCount;
    }
};
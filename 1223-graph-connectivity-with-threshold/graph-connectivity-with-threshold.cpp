class Solution {
public:
    vector<int> parent;
    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    void unionDs(int u, int v){
        int parentU = find(u);
        int parentV = find(v);
        if(parentU != parentV){
            parent[parentU] = parentV;
        }
    }
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<bool> isConnected;
        parent.resize(n + 1, 0);
        for(int i = 1; i <= n; i ++){
            parent[i] = i;
        }
        for(int u = threshold + 1; u < n + 1; u ++){
            for(int v = u * 2; v < n + 1; v += u){
                unionDs(u, v);
            }
        }
        for(auto query: queries){
            int u = query[0];
            int v = query[1];
            if(find(u) == find(v)){
                isConnected.push_back(true);
            }
            else isConnected.push_back(false);
        }
        return isConnected;
    }
};
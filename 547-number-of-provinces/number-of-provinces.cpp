class UnionFind {
public:
    vector<int> parent;
    UnionFind(int n){
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    void connect(int u, int v){
        int parentU = find(u);
        int parentV = find(v);
        if(parentU != parentV){
            parent[parentU] = parentV;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        int numOfComponent = n;
        for(int i = 0; i < n; i ++){
            for(int j = i + 1; j < n; j ++){
                if(isConnected[i][j] && uf.find(i) != uf.find(j)){
                    uf.connect(i, j);
                    numOfComponent --;
                }
            }
        }
        return numOfComponent;
    }
};
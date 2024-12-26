class UnionFind {
public:
    vector<int> parent;
    unordered_set<int> unique;
    int connected;
    UnionFind(int n){
        for(int i = 0; i <= n; i ++){
            parent.push_back(i);
            connected = 0;
        }
    }
    int find(int u){
        if(unique.find(u) == unique.end()){
            unique.insert(u);
            connected ++;
        }

        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int u, int v){
        int parentU = find(u);
        int parentV = find(v);
        if(parentU != parentV){
            parent[parentU] = parentV;
            connected --;
        }
    }
    int getComponent(){
        return connected;
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        UnionFind dsu(20001);
        for(auto stone : stones){
            int row = stone[0], col = stone[1] + 10001;
            dsu.merge(row, col);
        }
        return stones.size() - dsu.getComponent();
    }
};
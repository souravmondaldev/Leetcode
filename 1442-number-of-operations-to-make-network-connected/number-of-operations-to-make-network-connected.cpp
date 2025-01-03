class UnionFind {
public:
    int connections;
    vector<int> parent;
    UnionFind(int n){
        connections = n;
        parent.resize(n);
        for(int i = 0; i < n; i ++){
            parent[i] = i;
        }
    }

    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void unionConnection(int u, int v){
        int parentU = find(u);
        int parentV = find(v);
        if(parent[parentU] != parent[parentV]){
            connections --;
            parent[parentU] = parentV;
        }
    }
    int getConnectionCount(){
        for(int p : parent) cout << p << endl;
        return connections - 1;
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        UnionFind uf(n);
        for(auto connection : connections){
            int u = connection[0], v = connection[1];
            uf.unionConnection(u, v);
        }
        return uf.getConnectionCount();
    }
};
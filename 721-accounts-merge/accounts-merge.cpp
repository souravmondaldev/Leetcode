class UnionFind {
public:
    vector<int> parent;
    UnionFind(int n){
        parent.resize(n + 1);
        for(int i = 0; i <= n; i ++){
            parent[i] = i;
        }
    }

    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int u, int v){
        int parentU = find(u), parentV = find(v);
        if(parentU != parentV){
            parent[parentU] = parentV;
        }
    }

};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind uf(n);

        unordered_map<string, int> emailGroup;
        for(int i = 0; i < n; i ++){
            for(int j = 1; j < accounts[i].size(); j ++){
                string email = accounts[i][j];
                if(emailGroup.find(email) == emailGroup.end()){
                    emailGroup[email] = i;
                }
                else uf.merge(i, emailGroup[email]);
            }
        }

        unordered_map<int, vector<string>> connectedComponents;
        for(auto emailIt: emailGroup){
            int idx = emailIt.second;
            string email = emailIt.first;
            connectedComponents[uf.find(idx)].push_back(email);
        }
        vector<vector<string>> ans;
        for(auto componentIt : connectedComponents){
            int idx = componentIt.first;
            vector<string> comp = componentIt.second;

            vector<string> component = {accounts[idx][0]};
            component.insert(component.end(), comp.begin(), comp.end());
            sort(component.begin() + 1, component.end());
            ans.push_back(component);
        }
        return ans;
    }
};
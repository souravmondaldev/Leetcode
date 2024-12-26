class Solution {  
private:  
    vector<int> parent;  

public:  
    int find(int x) {  
        if(parent[x] == x) return x; 
        return parent[x] = find(parent[x]);  
    }  

    void unionDs(int u, int v) {  
        int parentU = find(u);  
        int parentV = find(v);  
        if (parentU != parentV) {  
            parent[parentU] = parentV;  
        }  
    }  

    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {  
        parent.resize(n, 0);  
        for (int i = 0; i < n; i++) {  
            parent[i] = i;  
        }  

        sort(edgeList.begin(), edgeList.end(), [&](auto a,auto b) {  
            return a[2] < b[2];  
        });  

        int m = queries.size();  
        vector<bool> ans(m, false);  

        for (int i = 0; i < m; i++) {  
            queries[i].push_back(i);  
        }  

        sort(queries.begin(), queries.end(), [&](auto a,auto b) {  
            return a[2] < b[2];  
        });  

        int idx = 0;  
        for (int i = 0; i < m; i++) {  
            int u = queries[i][0], v = queries[i][1], limit = queries[i][2], index = queries[i][3];  
            while (idx < edgeList.size() && edgeList[idx][2] < limit) {  
                unionDs(edgeList[idx][0], edgeList[idx][1]);  
                idx++;  
            }  
            if (find(u) == find(v)) {  
                ans[index] = true;  
            }  
        }  

        return ans;  
    }  
};
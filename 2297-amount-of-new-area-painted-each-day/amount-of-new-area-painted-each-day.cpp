class Solution {
public:
    int find(int a, vector<int> & parent){
        if(parent[a] == a) return a;
        return parent[a] = find(parent[a], parent);
    }
    void merge(int a, int b, vector<int> & parent){
        int rootA = find(a, parent), rootB = find(b, parent);
        if(parent[rootA] != parent[rootB]){
            parent[rootA] = rootB;
        }
    }
    int paintTile(int start, int end, vector<int>&parent){
        int area = 0;
        int currPos = start;
        while(currPos <= end){
            int root = find(currPos, parent);
            if(currPos == root){
                merge(currPos, currPos + 1, parent);
                area ++;
                currPos ++;
            }
            else currPos = root;
        }
        return area;
    }
    vector<int> amountPainted(vector<vector<int>>& paint) {
        int n = 0;
        for(auto p : paint){
            n = max(n, p[1]);
        }
        vector<int> parent(n + 2, 0);
        for(int i = 0; i < n + 2; i ++){
            parent[i] = i;
        }
        vector<int> res;
        for(auto p : paint){
            res.push_back(paintTile(p[0], p[1] - 1, parent));
        }
        return res;
    }
};
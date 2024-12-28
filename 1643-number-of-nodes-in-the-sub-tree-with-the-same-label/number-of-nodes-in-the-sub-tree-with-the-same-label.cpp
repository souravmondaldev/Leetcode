class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, unordered_set<int>> graph;
        for(auto edge : edges){
            int u = edge[0], v = edge[1];
            graph[u].insert(v);
            graph[v].insert(u);
        }
        vector<vector<int>> counts(n, vector<int> (26));
        queue<int> q;
        for(int node = 0; node < n; node ++){
            counts[node][labels[node] - 'a'] = 1;
            if(node != 0 && graph[node].size() == 1){
                q.push(node);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            int parent = *graph[curr].begin();
            graph[parent].erase(curr);
            for(int i = 0; i < 26; i ++){
                counts[parent][i] += counts[curr][i];
            }
            if(parent != 0 && graph[parent].size() == 1){
                q.push(parent);
            }
        }
        vector<int> ans;
        for(int node = 0; node < n; node ++){
            ans.push_back(counts[node][labels[node] - 'a']);
        }
        return ans;
    }
};
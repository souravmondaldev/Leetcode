class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> graph;
        for(auto prerequisite : prerequisites){
            int u = prerequisite[0];
            int v = prerequisite[1];
            graph[u].push_back(v);
        }
        vector<bool> ans;
        for(auto query : queries){
            int u = query[0];
            int v = query[1];
            ans.push_back(bfs(graph, u , v));
        }

        return ans;
    }
    bool bfs(unordered_map<int, vector<int>> &graph, int u, int v){
        queue<int> level;
        level.push(u);
        unordered_set<int> seen;
        seen.insert(u);
        cout << "Started " <<endl;
        while(!level.empty()){
            int size = level.size();
            while(size --){
                int node = level.front();
                // cout << node << endl;
                level.pop();
                if(node == v)
                    return true;
                for(int nghbr : graph[node]){
                    if(seen.count(nghbr)) continue;
                    level.push(nghbr);
                    seen.insert(nghbr);
                }
            }
        }
        return false;
    }
};
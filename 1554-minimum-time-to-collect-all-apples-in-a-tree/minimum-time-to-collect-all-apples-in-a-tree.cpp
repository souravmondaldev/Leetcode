class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<int> q;
        vector<int> parent(n, -1);
        vector<int> visited(n, 0);

        // BFS to set parent of each node
        q.push(0);
        visited[0] = 1;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int nei : adj[node]) {
                if (!visited[nei]) {
                    parent[nei] = node;
                    visited[nei] = 1;
                    q.push(nei);
                }
            }
        }

        // Count edges to traverse
        int time = 0;
        vector<int> added(n, 0); // mark if node contributes to path
        for (int i = 0; i < n; i++) {
            if (!hasApple[i]) continue;
            int node = i;
            while (node != 0 && !added[node]) {
                time += 2;         // edge used twice
                added[node] = 1;
                node = parent[node];
            }
        }

        return time;
    }
};

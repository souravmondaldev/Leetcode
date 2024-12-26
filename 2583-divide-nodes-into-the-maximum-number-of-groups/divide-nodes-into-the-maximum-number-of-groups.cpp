class Solution {
public:
    vector<int> parent;

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    void unionDsu(int u, int v) {
        int parentU = find(u);
        int parentV = find(v);
        if (parentU != parentV) {
            parent[parentU] = parentV;
        }
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> graph;
        parent.resize(n + 1, 0);

        // Initialize parent array for Union-Find
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        // Build the graph and perform Union-Find
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            unionDsu(u, v);
        }

        unordered_map<int, int> maxGroups;
        int maxSize = 0;

        // Process each connected component
        for (int i = 1; i <= n; i++) {
            int root = find(i);
            int groupSize = bfs(i, graph);
            if (groupSize == -1) {
                return -1; // Invalid graph structure
            }
            // cout << i << " parent " << find(i) << " maxGroups[root] " << maxGroups[root] << " groups " << groupSize <<endl;
            maxGroups[root] = max(maxGroups[root], groupSize);
        }

        // Sum up the maximum group sizes of all connected components
        for (auto& [_, size] : maxGroups) {
            maxSize += size;
        }

        return maxSize;
    }

    int bfs(int node, unordered_map<int, vector<int>>& graph) {
        queue<pair<int, int>> nodes;  // {node, level}
        unordered_map<int, int> seen;
        nodes.push({node, 1});
        seen[node] = 1;

        int maxLevel = 1;

        while (!nodes.empty()) {
            auto [currNode, currLevel] = nodes.front();
            nodes.pop();
            maxLevel = max(maxLevel, currLevel);

            for (int neighbor : graph[currNode]) {
                if (seen.find(neighbor) == seen.end()) {
                    seen[neighbor] = currLevel + 1;
                    nodes.push({neighbor, currLevel + 1});
                } else if (seen[neighbor] == currLevel) {
                    return -1; // Graph has an odd-length cycle
                }
            }
        }

        return maxLevel;
    }
};

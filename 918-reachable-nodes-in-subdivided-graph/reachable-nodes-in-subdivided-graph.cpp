class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int m, int n) {
        // Create adjacency list representation of the graph
        vector<vector<pair<int, int>>> graph(n);
        for (auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        // Distance array to store minimum distance to each node
        vector<int> dist(n, INT_MAX);
        dist[0] = 0;

        // Map to track how many "new nodes" on an edge have been used
        map<pair<int, int>, int> used;

        // Set to implement Dijkstra's algorithm
        set<pair<int, int>> st; // (distance, node)
        st.insert({0, 0}); // Start with node 0 at distance 0

        int ans = 0;

        // Dijkstra's algorithm to find shortest paths
        while (!st.empty()) {
            auto [d, node] = *st.begin();
            st.erase(st.begin());

            // If this distance is already larger than allowed moves, skip
            if (d > m) continue;

            // Increment reachable nodes
            ans++;

            for (auto& [nei, weight] : graph[node]) {
                // Track how many new nodes on this edge can be reached
                used[{node, nei}] = min(weight, m - d);

                // Calculate new distance to the neighbor
                int newDist = d + weight + 1;
                if (newDist < dist[nei]) {
                    st.erase({dist[nei], nei}); // Remove old distance if present
                    dist[nei] = newDist;
                    st.insert({newDist, nei}); // Add updated distance
                }
            }
        }

        // Count all reachable "new nodes" on each edge
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            int usedFromU = used[{u, v}];
            int usedFromV = used[{v, u}];
            ans += min(weight, usedFromU + usedFromV);
        }

        return ans;
    }
};

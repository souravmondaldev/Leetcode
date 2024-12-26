class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int, int> seenAtLevel;

        for (int i = 0; i < graph.size(); i++) {
            // If the node is already visited, skip it
            if (seenAtLevel.find(i) != seenAtLevel.end()) continue;

            // Perform BFS for each component
            queue<pair<int, int>> levelOrder;
            levelOrder.push({i, 1}); // Start with level 1 for this node
            seenAtLevel[i] = 1;

            while (!levelOrder.empty()) {
                int currNode = levelOrder.front().first;
                int currLevel = levelOrder.front().second;
                levelOrder.pop();

                for (int nghbr : graph[currNode]) {
                    if (seenAtLevel.find(nghbr) == seenAtLevel.end()) {
                        seenAtLevel[nghbr] = currLevel + 1;
                        levelOrder.push({nghbr, currLevel + 1});
                    } else if ((seenAtLevel[nghbr] ) == currLevel ) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};

class Solution {
public:
    int checkWays(vector<vector<int>>& edges) {
        unordered_map<int, unordered_set<int>> adjacencyList;
        for (auto& edge : edges) {
            adjacencyList[edge[0]].emplace(edge[1]);
            adjacencyList[edge[1]].emplace(edge[0]);
        }

        priority_queue<pair<int, int>> maxHeap; // {degree, node}
        for (auto& [node, neighbors] : adjacencyList) {
            maxHeap.push({neighbors.size(), node});
        }

        int totalNodes = maxHeap.size();
        bool hasMultipleWays = false;
        unordered_set<int> visitedNodes;

        while (!maxHeap.empty()) {
            auto [currentDegree, currentNode] = maxHeap.top();
            maxHeap.pop();

            int parentNode = 0;       // Potential parent node
            int minParentDegree = totalNodes + 1; // Smallest degree of a valid parent node

            // Find the parent node among visited nodes
            if (!visitedNodes.empty()) {
                for (auto neighbor : adjacencyList[currentNode]) {
                    if (visitedNodes.count(neighbor) && adjacencyList[neighbor].size() < minParentDegree) {
                        minParentDegree = adjacencyList[neighbor].size();
                        parentNode = neighbor;
                    }
                }
            }

            visitedNodes.emplace(currentNode); 

            // If the current node is the root
            if (parentNode == 0) {
                // The root must connect to all other nodes
                if (currentDegree != (totalNodes - 1)) {
                    return 0;
                }
                continue;
            }

            // Step 3: Validate parent-child relationships
            for (auto neighbor : adjacencyList[currentNode]) {
                if (neighbor == parentNode) continue; // Skip the parent
                if (adjacencyList[parentNode].count(neighbor) == 0) {
                    return 0; // The parent must be connected to all neighbors of the current node
                }
            }

            // Step 4: Check for multiple ways
            if (currentDegree == minParentDegree) {
                hasMultipleWays = true;
            }
        }

        // Return the result
        return hasMultipleWays ? 2 : 1; // Return 2 if multiple ways exist, otherwise 1
    }
};

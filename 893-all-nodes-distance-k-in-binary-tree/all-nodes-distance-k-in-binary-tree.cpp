/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent; // child -> parent
        buildParentMap(root, nullptr, parent);
        
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);
        int dist = 0;
        
        while (!q.empty()) {
            int size = q.size();
            if (dist == k) break;
            dist++;
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                if (node->left && visited.insert(node->left).second) q.push(node->left);
                if (node->right && visited.insert(node->right).second) q.push(node->right);
                if (parent[node] && visited.insert(parent[node]).second) q.push(parent[node]);
            }
        }
        
        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }

private:
    void buildParentMap(TreeNode* node, TreeNode* par, unordered_map<TreeNode*, TreeNode*>& parent) {
        if (!node) return;
        parent[node] = par;
        buildParentMap(node->left, node, parent);
        buildParentMap(node->right, node, parent);
    }
};

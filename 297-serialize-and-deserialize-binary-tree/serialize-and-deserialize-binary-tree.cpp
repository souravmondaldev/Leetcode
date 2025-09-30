/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Helper function for serializing the tree
    void dfsSerialize(TreeNode* root, vector<string> &res) {
        if (root == nullptr) {
            res.push_back("nullptr");
            return;
        }
        res.push_back(to_string(root->val));
        dfsSerialize(root->left, res);
        dfsSerialize(root->right, res);
    }

    // Encodes a tree to a single string
    string serialize(TreeNode* root) {
        vector<string> res;
        dfsSerialize(root, res);
        string ans = "";
        for (string s : res) {
            ans += s + ",";
        }
        // Remove trailing comma
        ans.pop_back();
        return ans;
    }

    // Helper function for deserializing the tree
    TreeNode* dfsDeserialize(vector<string> &nodes, int &idx) {
        if (nodes[idx] == "nullptr") {
            idx += 1; // Move to the next node
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(nodes[idx]));
        idx += 1; // Move to the next node
        node->left = dfsDeserialize(nodes, idx);
        node->right = dfsDeserialize(nodes, idx);
        return node;
    }

    // Decodes your encoded data to tree
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string node;
        vector<string> nodes;
        while (getline(ss, node, ',')) {
            nodes.push_back(node);
        }
        int idx = 0; // Start at the beginning of the nodes list
        return dfsDeserialize(nodes, idx);
    }
};

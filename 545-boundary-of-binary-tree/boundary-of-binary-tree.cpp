class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return {};
        
        vector<int> boundary;

        // Add root node if it's not a leaf
        if (!isLeaf(root)) {
            boundary.push_back(root->val);
        }

        // Get left boundary (excluding leaf nodes)
        getLeftBoundary(root->left, boundary);

        // Get all leaf nodes
        getLeafBoundary(root, boundary);

        // Get right boundary (excluding leaf nodes, in reverse order)
        vector<int> rightBoundary;
        getRightBoundary(root->right, rightBoundary);
        boundary.insert(boundary.end(), rightBoundary.rbegin(), rightBoundary.rend());

        return boundary;
    }

private:
    bool isLeaf(TreeNode* node) {
        return node->left == nullptr && node->right == nullptr;
    }

    void getLeftBoundary(TreeNode* root, vector<int>& boundary) {
        while (root) {
            if (!isLeaf(root)) {
                boundary.push_back(root->val);
            }
            // Move to the next boundary node
            root = (root->left) ? root->left : root->right;
        }
    }

    void getLeafBoundary(TreeNode* root, vector<int>& boundary) {
        if (root == nullptr) return;

        if (isLeaf(root)) {
            boundary.push_back(root->val);
        }

        getLeafBoundary(root->left, boundary);
        getLeafBoundary(root->right, boundary);
    }

    void getRightBoundary(TreeNode* root, vector<int>& boundary) {
        while (root) {
            if (!isLeaf(root)) {
                boundary.push_back(root->val);
            }
            // Move to the next boundary node
            root = (root->right) ? root->right : root->left;
        }
    }
};

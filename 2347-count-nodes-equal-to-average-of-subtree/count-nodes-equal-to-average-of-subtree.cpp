/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int count = 0;
    pair<int, int> postOrder(TreeNode* root) {
        if(!root)
            return {};
        pair<int, int> left = postOrder(root->left);
        pair<int, int> right = postOrder(root->right);
        int nodeSum = left.first + root->val + right.first;
        int nodeCount = left.second + 1 + right.second;
        if(root->val == nodeSum / nodeCount)
            count ++;
        return {nodeSum, nodeCount};
    }
    int averageOfSubtree(TreeNode* root) {
        postOrder(root);
        return count;
    }
};
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
    int helper(TreeNode* node, int currMax, int currMin){
        if(!node)
            return currMax - currMin;
        currMax = max(currMax, node->val);
        currMin = min(currMin, node->val);
        int left = helper(node->left, currMax, currMin);
        int right = helper(node->right, currMax, currMin);
        return max(left, right);
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root)
            return 0;
        return helper(root, root->val, root->val);
    }
};
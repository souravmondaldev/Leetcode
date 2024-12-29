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
    int maxSum= INT_MIN;
    int maxGain(TreeNode * node){
        if(!node) return 0;
        int leftSum = max(maxGain(node->left), 0);
        int rightSum= max(maxGain(node->right), 0);
        int newSum= node->val + leftSum+ rightSum;
        maxSum= max(maxSum, newSum);
        return node->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        maxGain(root);
        return maxSum;
    }
};
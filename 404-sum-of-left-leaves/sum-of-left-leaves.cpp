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
    int sum = 0;
    int sumOfLeft(TreeNode* root, int left){
        if(root == NULL)  return 0;
        if(!root->left && !root->right && left ==1)
            return root->val;
        return sumOfLeft(root->left, 1) + sumOfLeft(root->right, 0);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeft(root, 0);
        
    }
};
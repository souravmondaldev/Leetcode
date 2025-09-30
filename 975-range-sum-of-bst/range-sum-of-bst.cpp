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
    int getSum(TreeNode* root, int low, int high){
        if(!root) return 0;
        int validRangeSumSoFar = 0;
        if(root->val>= low && root->val <= high){
            validRangeSumSoFar = root->val;
        }
        return validRangeSumSoFar + getSum(root->left, low, high) + getSum(root->right, low, high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return getSum(root,low,high);
    }
};
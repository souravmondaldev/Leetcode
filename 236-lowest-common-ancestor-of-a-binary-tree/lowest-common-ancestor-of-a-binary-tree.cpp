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
private:
    TreeNode* ans = new TreeNode(-1);
    bool recursiveTree(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == NULL)
            return false;
        
        int left = recursiveTree(root->left, p, q) ? 1 : 0;
        int right = recursiveTree(root->right, p, q) ? 1 : 0;
        int mid = (root == p || root == q) ? 1 : 0;

        if(left + mid + right >= 2)
            ans = root;

        return (left + mid + right) > 0;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recursiveTree(root, p, q);
        return ans;
    }
};
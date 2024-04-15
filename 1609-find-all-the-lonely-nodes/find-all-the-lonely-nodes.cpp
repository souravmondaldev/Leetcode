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
    vector<int> getNode(TreeNode * root, vector<int>& ans) {
        if(!root) {
            return ans;
        }
        if(root->left and root->right) {
            ans = getNode(root->left,ans);
            return getNode(root->right, ans);
        }
        if(root->left) {
            ans.push_back(root->left->val);
            if(!root->left->left and !root->left->right) {
                return ans;
            }
            return getNode(root->left, ans);
        }
        if(root->right) {
            ans.push_back(root->right->val);
            if(!root->right->left and !root->right->right) {
                return ans;
            }
            return getNode(root->right, ans);
        }
        return ans;
    }
    void getNodes(TreeNode* root, vector<int> &ans){
        if(!root)   return;
        if(root->left && !root->right){
            ans.push_back(root->left->val);
        }
        if(!root->left && root->right){
            ans.push_back(root->right->val);
        }
        getNodes(root->left, ans);
        getNodes(root->right, ans);
        
    }
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ans;
        getNodes(root,ans);
        return ans;
    }
};
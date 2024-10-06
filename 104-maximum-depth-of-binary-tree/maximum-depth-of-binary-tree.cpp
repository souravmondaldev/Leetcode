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
    int maxDepthTree(TreeNode* root){
        if(root == nullptr)
            return 0;
        return max(1 + maxDepthTree(root->left), 1 + maxDepthTree(root->right));
    }
    int maxDepthTreeBfs(TreeNode* root){
        if(root == nullptr)
            return 0;
        int count = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, count});
        while(!q.empty()){
            auto nodePair = q.front();
            q.pop();
            TreeNode* node = nodePair.first;
            int currCount = nodePair.second;
            count = max(count, currCount);
            if(node->left){
                q.push({node->left, count + 1});
            }
            if(node->right){
                q.push({node->right, count + 1});
            }
        }
        return count;
    }
    int maxDepth(TreeNode* root) {
        return maxDepthTree(root);
    }
};
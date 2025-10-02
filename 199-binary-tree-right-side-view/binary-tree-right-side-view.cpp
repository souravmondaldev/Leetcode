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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)
            return {};
        queue<TreeNode*> nodes;
        vector<int> rightView;
        nodes.push(root);
        while(!nodes.empty()){
            int levelSize = nodes.size();
            for(int i = 1; i <= levelSize; i ++){
                auto node = nodes.front();
                nodes.pop();
                if(i == levelSize){
                    rightView.push_back(node->val);
                }
                if(node->left){
                    nodes.push(node->left);
                }
                if(node->right){
                    nodes.push(node->right);
                }
            }
        }

        return rightView; 
    }
};

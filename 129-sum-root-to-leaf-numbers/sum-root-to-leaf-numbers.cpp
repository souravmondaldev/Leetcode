/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int sumOfPaths(TreeNode* root, int sum) {
        if (root == NULL)
            return 0;

        sum = sum * 10 + root->val;
        if (!root->left && !root->right)
            return sum;

        return sumOfPaths(root->left, sum) + sumOfPaths(root->right, sum);
    }
    int sumNumbers(TreeNode* root) { 
        // return sumOfPaths(root, 0); 
        int ans = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        while(!q.empty()){
            int sz = q.size();
            while(sz -- ){
                pair<TreeNode*, int> topNodeQ = q.front();
                q.pop();
                TreeNode* topNode = topNodeQ.first;
                int val = topNodeQ.second;
                if(!topNode->left && !topNode->right){
                    ans += val;
                }
                if(topNode->left)
                    q.push({topNode->left, val*10 + topNode->left->val});
                if(topNode->right)
                    q.push({topNode->right, val*10 + topNode->right->val});
            }
        }
        return ans;
    }
};
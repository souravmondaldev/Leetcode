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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        map<int, vector<int>> map;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(!q.empty()){
            int size = q.size();
            // for(int i = 0; i < size; i ++){
                TreeNode* curr = q.front().first;
                int dir = q.front().second;
                q.pop();

                map[dir].push_back(curr->val);
                if(curr->left)
                    q.push({curr->left, dir - 1});
                if(curr->right)
                    q.push({curr->right, dir + 1});
            // }
        }
        for(auto i : map){
            res.push_back(i.second);
        }

        return res;
    }
};
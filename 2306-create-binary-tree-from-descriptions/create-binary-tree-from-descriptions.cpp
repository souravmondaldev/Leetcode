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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_set<int> parents, childs;
        unordered_map<int, vector<pair<int, int>>> parentToChild;
        for(auto description : descriptions){
            int parent = description[0], child = description[1], isLeft = description[2];
            parents.insert(parent);
            parents.insert(child);
            childs.insert(child);
            parentToChild[parent].push_back({child, isLeft});
        }
        for(auto child : childs){
            if(parents.find(child) != parents.end()){
                parents.erase(child);
            }
        }
        TreeNode* root = new TreeNode(*parents.begin());
        queue<TreeNode*> path;
        path.push(root);
        while(!path.empty()){
            TreeNode* parent = path.front();
            path.pop();
            for(auto childInfo : parentToChild[parent->val]){
                int child = childInfo.first, isLeft = childInfo.second;
                TreeNode * childNode = new TreeNode(child);
                path.push(childNode);
                if(isLeft)
                    parent->left = childNode;
                else parent->right = childNode;
            }
        }
        return root;
    }
};
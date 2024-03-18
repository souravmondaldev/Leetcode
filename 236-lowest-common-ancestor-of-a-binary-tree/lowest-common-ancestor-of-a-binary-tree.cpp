/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // Recusive solution
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
    // TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //     recursiveTree(root, p, q);
    //     return ans;
    // }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stack;
        unordered_map<TreeNode*, TreeNode*> parents;
        parents[root] = NULL;
        stack.push(root);
        while(parents.find(p) == parents.end() || parents.find(q) == parents.end()){
            TreeNode* node = stack.top();
            stack.pop();
            if(node->left){
                parents[node->left] = node;
                stack.push(node->left);
            }
            if(node->right){
                parents[node->right] = node;
                stack.push(node->right);
            }
        }
        unordered_set<TreeNode*> ancestors;
        while(p != NULL){
            ancestors.insert(p);
            p = parents[p];
        }
        while(ancestors.find(q) == ancestors.end()){
            q = parents[q];
        }
        return q;
    }
};
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
    bool isSameTreeRecursive(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr)
            return true;
        if(p == nullptr && q != nullptr)
            return false;
        if(p != nullptr && q == nullptr)
            return false;
        if(p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    bool isSameTreeBFS(TreeNode* pNode, TreeNode* qNode){
        queue<TreeNode*> queue; 
        queue.push(pNode);
        queue.push(qNode);
        while(!queue.empty()){
            TreeNode* p = queue.front();
            queue.pop();
            TreeNode* q = queue.front();
            queue.pop();
            if(p == nullptr && q == nullptr)
                continue;
            if(p == nullptr && q != nullptr)
                return false;
            if(p != nullptr && q == nullptr)
                return false;
            if(p->val != q->val)
                return false;
            queue.push(p->left);
            queue.push(q->left);
            queue.push(p->right);
            queue.push(q->right);
        }
        return true;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameTreeBFS(p, q);
    }
};
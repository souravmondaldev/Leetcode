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
    void helper(TreeNode* root, int row, int column, map<int, map<int, multiset<int>>> &columnToNodeMapping){
        if(!root)
            return;
        columnToNodeMapping[column][row].insert(root->val);
        if(root->left)
            helper(root->left, row + 1, column - 1, columnToNodeMapping);
        if(root->right)
            helper(root->right, row + 1, column + 1, columnToNodeMapping);
    }
    // O(NlogN) O(N)
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mapping;
        helper(root, 0, 0, mapping);
        vector<vector<int>> traversalOutput;
        for (auto const& [column, rowMap] : mapping) {
            vector<int> currentCol;
            for (auto const& [row, valueSet] : rowMap) {
                currentCol.insert(currentCol.end(), valueSet.begin(), valueSet.end());
            }
            traversalOutput.push_back(currentCol);
        }

        return traversalOutput;
    }
};
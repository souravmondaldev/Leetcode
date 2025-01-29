/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        unordered_set<int> seen;
        for(Node* node : tree){
            for(Node* childNode : node->children){
                seen.insert(childNode->val);
            }
        }
        Node* root = nullptr;
        for(Node* node : tree){
            if(!seen.count(node->val)){
                root = node;
                // break;
            }
        }
        return root;
    }
};
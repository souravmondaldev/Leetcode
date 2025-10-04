/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    void inorderTraversal(Node* node, Node* &prev, Node* &head){
        if(node == nullptr)
            return;
        inorderTraversal(node->left, prev, head);
        if(prev == nullptr){
            head = node;
        }
        else{
            prev->right = node;
            node->left = prev;
        }
        prev = node;
        inorderTraversal(node->right, prev, head);
    }
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr)
            return nullptr;
        Node* prev = nullptr;
        Node* head = nullptr;
        inorderTraversal(root, prev, head);
        head->left = prev;
        prev->right = head;
        
        return head;
    }
};
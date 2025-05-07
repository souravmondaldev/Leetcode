/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    unordered_set<Node*> getAllParents(Node* p){
        unordered_set<Node*> parents;
        parents.insert(p);
        while(p->parent != nullptr){
            parents.insert(p->parent);
            p = p->parent;
        }
        return parents;
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_set<Node*> parentsOfP = getAllParents(p);
        if(parentsOfP.count(q)) return q;
        while(q->parent != nullptr){
            if(parentsOfP.count(q->parent)) return q->parent;
            q = q->parent;
        }
        return q;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
// O(N + E) O(N) DFS
// class Solution {
// private:
//     unordered_map<Node*, Node*> visited;
// public:
//     Node* cloneGraph(Node* node) {
//         if(node == nullptr)
//             return node;
//         if(visited.count(node))
//             return visited[node];

//         Node* clonedNode = new Node(node->val);
//         visited[node] = clonedNode;
//         for(Node* neighbor: node->neighbors){
//             clonedNode->neighbors.push_back(cloneGraph(neighbor));
//         }

//         return visited[node];
//     }
// };

class Solution {
private:
   
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)
            return node;
        unordered_map<Node*, Node*> visited;
        queue<Node*> q;
        q.push(node);
        Node* clonedNode = new Node(node->val);
        visited[node] = clonedNode;
        while(!q.empty()){
            Node* currNode = q.front();
            q.pop();
            
            for(Node* neighbor: currNode->neighbors){
                if(visited.find(neighbor) == visited.end()){
                    visited[neighbor] = new  Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[currNode]->neighbors.push_back(visited[neighbor]);
            }
        }

        return visited[node];
    }
};
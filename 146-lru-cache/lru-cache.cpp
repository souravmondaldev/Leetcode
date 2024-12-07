class Node{
    public:
        int key;
        int value;
        Node* prev;
        Node *next;
    Node(int _key, int _val){
        key = _key;
        value = _val;
    }
};
class LRUCache {
private:
    int cap;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    unordered_map<int, Node*> nodeMap;
    void deleteNode(Node *node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }
    void addNode(Node *node){
        Node* nextNodeToHead = head->next;
        nextNodeToHead->prev = node;
        node->next = nextNodeToHead;
        head->next = node;
        node->prev = head;
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        tail->prev = head;
        head->next = tail;
    }
    
    int get(int key) {
        if(nodeMap.find(key) != nodeMap.end()){
            Node* node = nodeMap[key];
            int val = node->value;
            nodeMap.erase(key);
            deleteNode(node);
            addNode(node);
            nodeMap[key] = head->next;
            return val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(nodeMap.find(key) != nodeMap.end()){
            Node* node = nodeMap[key];
            nodeMap.erase(key);
            deleteNode(node);
        }
        if(nodeMap.size() == cap){
            nodeMap.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        nodeMap[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
class Node {
    public:
    int freq;                          // Frequency of the words in this node
    unordered_set<string> words;       // Set of words with this frequency
    Node* prev;
    Node* next;

    Node(int f) : freq(f), prev(nullptr), next(nullptr) {}
};

class AllOne {
public:
    Node *head, *tail;
    unordered_map<string, Node*> wordToNode;  // Maps each word to its corresponding node

    AllOne() {
        head = new Node(0);  // Dummy head node
        tail = new Node(0);  // Dummy tail node
        head->next = tail;
        tail->prev = head;
    }

    // insert a new node after a given node
    Node* insertNodeAfter(Node* node, int freq) {
        Node* newNode = new Node(freq);
        newNode->next = node->next;
        newNode->prev = node;
        node->next->prev = newNode;
        node->next = newNode;
        return newNode;
    }

    // remove a node if it has no words left
    void removeNodeIfEmpty(Node* node) {
        if (node->words.empty()) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
        }
    }

    // Increase the count of word
    void inc(string word) {
        if (wordToNode.find(word) != wordToNode.end()) {
            // Word is already in the list, update its frequency
            Node* currNode = wordToNode[word];
            currNode->words.erase(word);

            // Check if the next node has the correct frequency
            Node* nextNode = currNode->next;
            if (nextNode == tail || nextNode->freq != currNode->freq + 1) {
                nextNode = insertNodeAfter(currNode, currNode->freq + 1);
            }
            nextNode->words.insert(word);
            wordToNode[word] = nextNode;

            // Remove the current node if it's empty
            removeNodeIfEmpty(currNode);
        } else {
            // Word is new, add it just after head (freq = 1)
            Node* firstNode = head->next;
            if (firstNode == tail || firstNode->freq != 1) {
                firstNode = insertNodeAfter(head, 1);
            }
            firstNode->words.insert(word);
            wordToNode[word] = firstNode;
        }
    }

    // Decrease the count of word
    void dec(string word) {
        Node* currNode = wordToNode[word];
        currNode->words.erase(word);

        if (currNode->freq > 1) {
            // Check if the previous node has the correct frequency
            Node* prevNode = currNode->prev;
            if (prevNode == head || prevNode->freq != currNode->freq - 1) {
                prevNode = insertNodeAfter(currNode->prev, currNode->freq - 1);
            }
            prevNode->words.insert(word);
            wordToNode[word] = prevNode;
        } else {
            // If frequency becomes 0, remove the word entirely
            wordToNode.erase(word);
            
        }
        removeNodeIfEmpty(currNode);
        // Remove the current node if it's empty
        
    }

    // Get the word with the maximum frequency
    string getMaxKey() {
        if (tail->prev == head) return "";  // No words present
        return *tail->prev->words.begin();  // Return any word with max frequency
    }

    // Get the word with the minimum frequency
    string getMinKey() {
        if (head->next == tail) return "";  // No words present
        return *head->next->words.begin();  // Return any word with min frequency
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// class AllOne {
// public:
//     unordered_map<string, int> mp;
//     set<pair<int, string>> st;
//     AllOne() {
        
//     }
    
//     void inc(string key) {
//         st.erase({mp[key], key});
//         mp[key] ++;
//         st.insert({mp[key], key});
//     }
    
//     void dec(string key) {
//         st.erase({mp[key], key});
//         mp[key] --;
//         if(mp[key] > 0)
//             st.insert({mp[key], key});
//     }
    
//     string getMaxKey() {
//         return st.size() ? prev(st.end())->second : "";
//     }
    
//     string getMinKey() {
//         return st.size() ? st.begin()->second : "";
//     }
// };

// /**
//  * Your AllOne object will be instantiated and called as such:
//  * AllOne* obj = new AllOne();
//  * obj->inc(key);
//  * obj->dec(key);
//  * string param_3 = obj->getMaxKey();
//  * string param_4 = obj->getMinKey();
//  */
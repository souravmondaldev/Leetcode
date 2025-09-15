class TrieNode {
    public:
        TrieNode *left, *right;
        TrieNode() : left(NULL), right(NULL) {};
};

class Trie {
public:
    void insert(TrieNode* root, int num){
        TrieNode* curr = root;
        for(int i = 30; i >= 0 ; i --){
            int bit = (num >> i) & 1;
            if(bit == 0){
                if(!curr->left) curr->left = new TrieNode();
                curr = curr->left;
            }
            else {
                if(!curr->right) curr->right = new TrieNode();
                curr = curr->right;
            }
        }
    }
    int maxXor(TrieNode* root, int num){
        TrieNode* curr = root;
        int xorValue = 0;
        for(int i = 30; i >= 0; i --){
            int bit = (num>>i) & 1;
            if(bit == 0){
                if(curr->right){
                    xorValue |= (1 << i);
                    curr = curr->right;
                }
                else curr = curr->left;
            }
            else {
                if(curr->left){
                    xorValue |= (1 << i);
                    curr = curr->left;
                }
                else curr = curr->right;
            }
        }
        return xorValue;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        TrieNode* root = new TrieNode();
        Trie* trie = new Trie();
        for(int num : nums){
            trie->insert(root, num);
        }
        int max_ans = 0;
        for (int num : nums) {
            max_ans = max(max_ans, trie->maxXor(root, num));
        }
        return max_ans;
    }
};
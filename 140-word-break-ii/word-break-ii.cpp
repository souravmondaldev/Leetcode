class TrieNode {
public:
    unordered_map<char, TrieNode*> next; // Use char as the key
    bool isWord = false;
};

class Solution {
private:
    TrieNode* root = new TrieNode();
    
    void insert(TrieNode* root, const string& word) {
        for (char ch : word) {
            if (root->next.find(ch) == root->next.end()) {
                root->next[ch] = new TrieNode();
            }
            root = root->next[ch];
        }
        root->isWord = true;
    }
    
    // DFS to explore possible sentences
    void dfs(const string& s, int idx, TrieNode* node, string path, vector<string>& ans) {
        if (idx == s.length()) {
            if (node->isWord) {
                ans.push_back(path); // Add the full sentence to the result
            }
            return;
        }
        
        // Check for word breaks
        if (node->isWord) {
            dfs(s, idx, root, path + " ", ans);
        }
        
        // If we can continue exploring this path
        if (idx < s.length() && node->next.find(s[idx]) != node->next.end()) {
            dfs(s, idx + 1, node->next[s[idx]], path + s[idx], ans);
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (const string& word : wordDict) {
            insert(root, word);
        }
        
        vector<string> ans;
        dfs(s, 0, root, "", ans);
        return ans;
    }
};

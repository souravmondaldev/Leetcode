class TrieNode {
public:
    bool isEnd;
    
    unordered_map<string, TrieNode*> children;
    
    TrieNode() {
        isEnd = false;
    }
};

class Solution {
public:
    TrieNode *globalHead = new TrieNode();
    
    string extractFolder(string &folderName, int i) {
        int k = i;
        i++;
        
        while (i < folderName.size() and folderName[i] != '\/') {
            i++;
        }
        
        return folderName.substr(k + 1, i - k - 1);
    }
    
    bool insertFolder(TrieNode *root, string &folderName, int i) {
        if (i == folderName.size()) {
            root->isEnd = true;
            return true;
        }
        
        if (root->isEnd) {
            return false;
        }
        
        string subFolderName  = extractFolder(folderName, i);
        
        if (!root->children.count(subFolderName)) {
            root->children[subFolderName] = new TrieNode();
        }
        
        return insertFolder(root->children[subFolderName], folderName, i + subFolderName.size() + 1);
    }
    
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        for (auto &directory: folder) {
            if (insertFolder(globalHead, directory, 0)) {
                ans.push_back(directory);
            }
        }
        
        return ans;
    }
};
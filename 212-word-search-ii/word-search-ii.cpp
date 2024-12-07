class TrieNode {
    public:
        unordered_map<int, TrieNode*> next;
        bool isEnd;
        string word;
        TrieNode(){
            isEnd = false;
            word = "";
        }
};
    
class Solution {
private:
    void insertIntoTrie(TrieNode* root, string word){
        TrieNode * node = root;
        for(char ch : word){
            if(node->next.find(ch - 'a') == node->next.end()){
                node->next[ch - 'a'] = new TrieNode();
            }
            node = node->next[ch - 'a'];
        }
        node->word = word;
        node->isEnd = true;
    }

    bool serachInTrie(TrieNode* root, string word){
        TrieNode * node = root;
        for(char ch : word){
            if(node->next.find(ch - 'a') == node->next.end()){
                return false;
            }
            node = node->next[ch - 'a'];
        }
        return node->isEnd;
    }
    void searchMatrix(int i, int j, TrieNode* node, vector<vector<char>>& board,
        vector<string> &presentWords){
        char ch = board[i][j];
        if(node->next.find(ch -'a') == node->next.end() || ch == '#')
            return;
        node = node->next[ch - 'a'];
        if(node->isEnd){
            node->isEnd = false;
            presentWords.push_back(node->word);
        }
        
        board[i][j] = '#';
        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        for (auto& dir : directions) {
            int newRow = i + dir[0];
            int newCol = j + dir[1];
            if (newRow >= 0 && newRow < (int)board.size() && newCol >= 0 && newCol < (int)board[0].size()) {
                searchMatrix(newRow, newCol, node, board, presentWords);
            }
        }

        board[i][j] = ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> presentWords = {};
        TrieNode * root = new TrieNode();
        for(string word : words){
            insertIntoTrie(root, word);
        }
        for(int i = 0; i < board.size(); i ++){
            for(int j = 0; j < board[0].size(); j ++){
                searchMatrix(i, j, root, board, presentWords);
            }
        }
        return presentWords;
    }
};
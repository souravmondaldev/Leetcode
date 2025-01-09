
class TrieNode {
public:
    unordered_map<char, TrieNode*> next;
    bool isWordEnd;
    string word;
    TrieNode(): isWordEnd(false), word("") {}
};

  
class Solution {
    vector<vector<int>> dir = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

private:
    
    bool isSafe(int row, int col, int n, int m) {
        return (row<n && row>=0 && col<m && col>=0);
    }
    bool dfs(vector<vector<char>>& board, string word, int row, int col, int index) {
        if(index >= word.size()) {
            return true;
        }
        if(!isSafe(row, col, board.size(), board[0].size()) || board[row][col]!=word[index])
            return false;
        
        board[row][col] = '#'; 
        bool backTrack = false;
        for(int i=0;i<4;i++) {
            int currRow = row + dir[i][0];
            int currCol = col + dir[i][1];
            
            backTrack = dfs(board, word, currRow, currCol, index+1);
            if(backTrack)
                break;
        }
        board[row][col] = word[index];
        return backTrack;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                if(dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
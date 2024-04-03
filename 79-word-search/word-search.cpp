class Solution {
private:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    
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
            int currRow = row + x[i];
            int currCol = col + y[i];
            
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
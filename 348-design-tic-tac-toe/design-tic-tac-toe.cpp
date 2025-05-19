class TicTacToe {
public:
    vector<int> rows, cols;
    int diagonal, antidiagonal, size;
    TicTacToe(int n) {
      size = n;
      diagonal = 0;
      antidiagonal = 0;
      rows.assign(n, 0);
      cols.assign(n, 0);
    };
    
    int move(int row, int col, int player) {
       int point = player == 1 ? 1 : -1;
       rows[row] += point;
       cols[col] += point;  
       if(row == col) diagonal += point;
       if(row == size - 1 - col) antidiagonal += point;
       if(abs(rows[row]) == size || abs(cols[col]) == size || abs(diagonal) == size || 
          abs(antidiagonal) == size){
          return player;
       }
       return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
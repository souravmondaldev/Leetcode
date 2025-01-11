class Solution {
public:
    bool bfs(vector<vector<int>>&grid, int row, int col, int color){
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        bool isClosed = true;
        while(!q.empty()){
            int currentRow = q.front().first, currentColumn = q.front().second;
            q.pop();
            grid[currentRow][currentColumn] = color;
            if(currentRow == 0 || currentColumn == 0 || currentRow == n - 1 || currentColumn == m - 1)
                isClosed = false;
            for(auto direction : directions){
                int nextRow = currentRow + direction[0];
                int nextColumn = currentColumn + direction[1];
                if(nextRow >= 0 && nextColumn >= 0 && nextRow < n && nextColumn < m && grid[nextRow][nextColumn] == 0){
                    q.push({nextRow, nextColumn});
                    grid[nextRow][nextColumn] = color;
                }
            }
        }
        return isClosed;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int numberOfIslands = 0;
        int color = 2;
        int n = grid.size(), m = grid[0].size();
        for(int row = 0; row < n; row ++){
            for(int col = 0; col < m; col ++){
                if(grid[row][col] == 0){
                    bool validIsland = bfs(grid, row, col, color);
                    if(validIsland){
                        // cout << row << " " << col << endl;
                        color ++;
                        numberOfIslands ++;
                    }
                }
            }
        }
        return numberOfIslands;
    }
};
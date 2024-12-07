class Solution {
private:
    bool validPos(int row, int col, int m, int n){
        return row >= 0 && col >= 0 && row < m && col < n;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if(rows == 0)
            return 0;
        int cols = grid[0].size();
        int islandCount = 0;
        vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int row = 0; row < rows; row ++){
            for(int col = 0; col < cols; col ++){
                if(grid[row][col] == '1'){
                    islandCount ++; 
                    grid[row][col] = -1;
                    queue<pair<int, int>> island;
                    island.push({row, col});
                    while(!island.empty()){
                        int tRow = island.front().first;
                        int tCol = island.front().second;
                        island.pop();
                        for(auto dir : directions){
                            int x = tRow + dir[0];
                            int y = tCol + dir[1];
                            if(validPos(x, y, rows, cols) && grid[x][y] == '1'){
                                grid[x][y] = -1;
                                island.push({x, y});
                            }
                        }
                    }
                }
            }
        }
        return islandCount;
    }
};
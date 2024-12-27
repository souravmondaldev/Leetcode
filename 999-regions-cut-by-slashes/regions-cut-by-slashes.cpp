
class Solution {  
public:  
    int regionsBySlashes(vector<std::string>& grid) {  
       int gridSize = grid.size();
       vector<vector<int>> expandedGrid(gridSize * 3, vector<int> (gridSize * 3, 0));
       for(int bi = 0; bi < gridSize; bi ++){
            for(int bj = 0; bj < gridSize; bj ++){
                int i = bi * 3, j = bj * 3;
                if(grid[bi][bj] == '\\'){
                    expandedGrid[i][j] = 1;
                    expandedGrid[i + 1][j + 1] = 1;
                    expandedGrid[i + 2][j + 2] = 1;
                }
                else if(grid[bi][bj] == '/'){
                    expandedGrid[i + 2][j] = 1;
                    expandedGrid[i + 1][j + 1] = 1;
                    expandedGrid[i][j + 2] = 1;
                }
            }
       }
       int regions = 0;
       for(int i = 0; i < gridSize * 3; i ++){
            for(int j = 0; j < gridSize * 3; j ++){
                if(expandedGrid[i][j] == 0){
                    floodfill(i, j, gridSize * 3, expandedGrid);
                    regions ++;
                }
            }
       }
       return regions;
    }
    void floodfill(int i, int j, int n, vector<vector<int>> &grid){
        queue<pair<int, int>> q;
        vector<vector<int>> dirs = {{-1, 0}, {0 , -1}, {1, 0}, {0, 1}};
        grid[i][j] = 1;
        q.push({i, j});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto dir : dirs){
                int newX = dir[0] + x, newY = dir[1] + y;
                if(newX >= 0 && newY >= 0 && newX < n && newY < n && grid[newX][newY] == 0){
                    grid[newX][newY] = 1;
                    q.push({newX,newY});
                }
            }
        }
    }
};
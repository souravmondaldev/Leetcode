class Solution {
public:
    int bfs(vector<vector<int>>&grid, int i, int j){
        
        vector<vector<int>> dimensions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        queue<pair<int, int>> q;
        q.push({i, j});
        int area = 1;
        grid[i][j] = -1;
        while(!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            for(auto dir : dimensions){
                int nX = x + dir[0], nY = y + dir[1];
                if(nX >= 0 && nY >= 0 && nX < grid.size() && nY < grid[0].size() && grid[nX][nY] == 1){
                    area ++;
                    grid[nX][nY] = -1;
                    q.push({nX, nY});
                }
            }
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(grid[i][j] == 1){
                    maxArea = max(maxArea, bfs(grid, i, j));
                }
            }
        }
        return maxArea;
    }
};
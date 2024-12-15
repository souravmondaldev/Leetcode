class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>&grid, queue<pair<int, int>> &q,vector<vector<int>> &dirs, int n){
        if(i < 0 || j  < 0 || i >= n || j >= n || grid[i][j] != 1) return;
        for(auto dir : dirs){
            q.push({i, j});
            grid[i][j] = -1;
            dfs(i + dir[0], j + dir[1], grid, q, dirs, n);
        }
    }
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        bool foundLand = false;
        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                if(grid[i][j] == 1){
                    dfs(i, j, grid, q, dirs, n);
                    foundLand = true;
                    break;
                }
            }
            if(foundLand) break;
        }
        int steps = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz --){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(auto dir : dirs){
                    int dx = x + dir[0];
                    int dy = y + dir[1];
                    if(dx >= 0 && dy >= 0 && dx < n && dy < n){
                        if(grid[dx][dy] == 1)
                            return steps;
                        if(grid[dx][dy] == 0){
                            grid[dx][dy] = -1;
                            q.push({dx, dy});
                        }
                    }
                }   
            }
            steps ++;
        }
        return -1;
    }
};
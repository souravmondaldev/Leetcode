class Solution {
    vector<vector<int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool validPath(int row, int col, int n){
        return row >= 0 && col >= 0 && row < n && col < n;
    }
public: 
    void bfs(vector<vector<int>>& grid, int i, int j, set<int> &maxDepthInAllPaths){
        priority_queue<pair<int, pair<int, int>>> paths;
        paths.push({-grid[0][0], {i, j}});
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[i][j] = true;
        while(!paths.empty()){
            int numOfPath = paths.size();
            for(int path = 0; path < numOfPath; path ++){
                auto pathInfo = paths.top();
                paths.pop();
                int row = pathInfo.second.first, col = pathInfo.second.second,
                    time = pathInfo.first;
                grid[row][col] = -1;
                if(row == n - 1 && col == n - 1){
                    maxDepthInAllPaths.insert(-time);
                }
                for(auto direction : DIRECTIONS){
                    int newRow = row + direction[0], newCol = col + direction[1];
                    if(validPath(newRow, newCol, n) && visited[newRow][newCol] == false){
                        int maxDepth = max(-time, grid[newRow][newCol]);
                        visited[newRow][newCol] = true;
                        paths.push({-maxDepth, {newRow, newCol}});
                        // cout << newRow << " " << newCol << " " << maxDepth <<endl;
                    }
                }
            }
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 1) return grid[0][0];
        set<int> maxDepthInAllPaths;
        bfs(grid, 0, 0, maxDepthInAllPaths);
        for(auto num : maxDepthInAllPaths){
            cout << num <<endl;
        }
        return *begin(maxDepthInAllPaths);
    }
};
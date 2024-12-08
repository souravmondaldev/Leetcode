class Solution {
private:
    vector<int> parent;
    vector<int> rank;
    int find(int idx){
        if(parent[idx] != idx){
            parent[idx] = find(parent[idx]);
        }
        return parent[idx];
    }
    bool unionSet(int x, int y){
        int parentX = find(x);
        int parentY = find(y);
        if(parentX != parentY){
            if(rank[parentX] > rank[parentY]){
                parent[parentY] = parentX;
            }
            else if(rank[parentX] < rank[parentY]){
                parent[parentX] = parentY;
            }
            else {
                parent[parentX] = parentY;
                rank[parentY] ++;
            }
            return true;
        }
        return false;
    }
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        parent.resize(m * n, -1);
        rank.resize(m * n, 0);
        vector<vector<int>> grid(m, vector<int>(n, 0));
        vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<int> islands;
        int islandCount = 0;
        for(auto &pos : positions){
            int row = pos[0];
            int col = pos[1];
            int idx = row * n + col;
            parent[idx] = idx;
            if(grid[row][col] == 1){
                islands.push_back(islandCount);
                continue;
            }
            grid[row][col] = 1;
            islandCount ++;
            for(auto &dir : directions){
                int nRow = row + dir[0];
                int nCol = col + dir[1];
                int nIdx = nRow * n + nCol;
                if(nRow < m && nRow >= 0 && nCol < n && nCol >= 0 && grid[nRow][nCol] == 1){
                    if(unionSet(idx, nIdx))
                        islandCount --;
                }
            }
            islands.push_back(islandCount);
        }
        return islands;
    }
};
class UnionFind {
public:
    vector<int> parent;
    UnionFind(int n){
        parent.resize(n);
        for(int i = 0; i < n; i ++){
            parent[i] = i;
        }
    }
    int find(int u){
        if(parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }
    void mergeIsland(int u, int v){
        int parentU = find(u), parentV = find(v);
        if(parentU != parentV){
            parent[parentU] = parentV;
        }
    }
};
class Solution {
public:
/*
create n*m grid
using unionfind to join island in all 4 direction if available
increment the island whenever new island
*/
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<int> islands;
        vector<vector<int>> directions = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        vector<vector<int>> grid(m, vector<int>(n, 0));
        UnionFind uf(m*n);
        int islandCount = 0;
        for(auto position : positions){
            int x = position[0], y = position[1];
            if(grid[x][y] == 1){
                islands.push_back(islandCount);
                continue;
            }
            islandCount ++;
            grid[x][y] = 1;
            int currentIslandIdx =  x*n + y;
            for(auto dir : directions){
                int nextX = x + dir[0], nextY = y + dir[1];
                if(nextX >= 0 && nextY >= 0 && nextX < m && nextY < n && grid[nextX][nextY] == 1){
                    int nextIslandIdx =  nextX*n + nextY;
                    if(uf.find(currentIslandIdx) != uf.find(nextIslandIdx)){
                        uf.mergeIsland(nextIslandIdx, currentIslandIdx);
                        islandCount --;
                    }
                }
            }
            islands.push_back(islandCount);
        }
        return islands;
    }
};
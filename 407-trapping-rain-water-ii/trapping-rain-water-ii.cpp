class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size();
        priority_queue<pair<int, pair<int, int>>> pq;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(i  == 0 || j == 0 || i == n - 1 || j == m - 1){
                    vis[i][j] = 1;
                    pq.push({-heightMap[i][j], {i, j}});
                }                
            }
        }

        vector<vector<int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        int water = 0;
        while(!pq.empty()){
            auto minHeightInfo = pq.top();
            pq.pop();
            int minHeight = -minHeightInfo.first;
            int x = minHeightInfo.second.first, y = minHeightInfo.second.second;

            for(auto dir : dirs){
                int newX = x + dir[0], newY = y + dir[1];
                if(newX >= 0 && newY >= 0 && newX < n && newY < m && vis[newX][newY] == 0){
                    vis[newX][newY] = 1;
                    pq.push({-max(heightMap[newX][newY], minHeight), {newX, newY}});
                    water += max(0, minHeight - heightMap[newX][newY]);
                }
            }
        }
        return water;
    }
};
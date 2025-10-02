class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int delta[8][2] = {{0,1}, { 1,0}, {0,-1}, {-1,0},{-1,-1},{1,1}, {1,-1}, {-1,1}};
        queue<pair<pair<int, int>, int>> q;
        int n = grid.size();
        if(n==0 or grid[0][0]==1 or grid[n-1][n-1]==1)
            return -1;
        else q.push({{0,0},1});
        int minDis = INT_MAX;
        while(!q.empty()){
            auto el = q.front();
            auto pos = el.first;
            auto dis = el.second;
            q.pop();
            int x = pos.first;
            int y = pos.second;
            
            if(x== n-1 and y ==n-1)
                return dis;
            for(auto dt : delta){
                int dx = x+ dt[0];
                int dy = y+ dt[1];
                if(dx>=0 and dy>=0 and dx<n and dy<n and grid[dx][dy]==0){
                    grid[dx][dy] = -1;
                    q.push({{dx, dy}, dis+1});
                }
            }
                
        }
        
        return -1;
    }
};
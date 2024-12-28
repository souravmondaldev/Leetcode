class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>
            pq;
        int time = 0;
        int n = moveTime.size(), m = moveTime[0].size();
        pq.push({time, {0, 0}});
        vector<vector<int>> distArr (n, vector<int>(m, INT_MAX));
        distArr[0][0] = 0;
        vector<vector<int>> dirs = {{-1,0}, {0, -1}, {1, 0}, {0, 1}};
        while(!pq.empty()){
            auto topEl = pq.top();
            pq.pop();
            int time = topEl.first;
            int x = topEl.second.first;
            int y = topEl.second.second;
            if(x == n - 1 && y == m - 1) return time;
            if(time > distArr[x][y]) continue;
            for(auto dir : dirs){
                int dx = dir[0], dy = dir[1];
                int newX = x + dx, newY = y + dy;
                if(newX >= 0 && newY >= 0 && newX < n && newY < m){
                    int remainingTime = max(0, moveTime[newX][newY] - time);
                    if(distArr[newX][newY] > time + remainingTime + 1){
                        distArr[newX][newY] = time + 1 + remainingTime;
                        pq.push({distArr[newX][newY], {newX, newY}});
                    }
                }
            }
        }
        return -1;
    }
};
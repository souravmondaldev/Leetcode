class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0;
        set<pair<int, int>> obs;
        for(auto obstacle : obstacles){
            obs.insert({obstacle[0], obstacle[1]});
        }
        int direction = 0, ans = 0;
        for(int command : commands){
            switch(command){
                case -1:
                    direction = (direction + 1) % 4;
                    break;
                case -2:
                    direction = (direction - 1 + 4) % 4;
                    break;
                default:
                    int dx = directions[direction][0], dy = directions[direction][1];
                    for(int i = 0; i < command; i ++){
                        if(obs.count({x + dx, y + dy})){
                            break;
                        }
                        x += dx;
                        y += dy;
                        
                    }
                    ans = max(ans, x*x + y*y);
                    break;
            }
        }
        return ans;
    }
};
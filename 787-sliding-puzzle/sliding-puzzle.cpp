class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        vector<vector<int>> swapPos = {
            {1, 3},
            {2, 0, 4},
            {1, 5},
            {0, 4},
            {3, 5, 1},
            {2, 4}
        };
        string targetStatus = "123450";
        string currentStatus = "";
        for(int i = 0; i < 2; i ++){
            for(int j = 0; j < 3; j ++){
                currentStatus += to_string(board[i][j]);
            }
        }
        unordered_set<string> visited;
        queue<string> q;
        q.push(currentStatus);
        visited.insert(currentStatus);
        int minMove = 0;
        while(!q.empty()){
            int q_size = q.size();
            while(q_size --){
                string status = q.front();
                q.pop();
                if(status == targetStatus)
                    return minMove;
                int zeroPos = status.find('0');
                for(auto pos : swapPos[zeroPos]){
                    string nextStatus = status;
                    swap(nextStatus[zeroPos], nextStatus[pos]);
                    if(visited.count(nextStatus)) continue;
                    q.push(nextStatus);
                    visited.insert(nextStatus);
                }
            }
            minMove ++;
        }
        return -1;
    }
};
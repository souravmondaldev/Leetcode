class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> bricksCnt;
        for(int i = 0; i < heights.size() - 1; i ++){
            int climb = heights[i + 1] - heights[i];
            if(climb <= 0) continue;
            bricks -= climb;
            bricksCnt.push(climb);
            if(bricks < 0 && ladders == 0) return i;
            if(bricks < 0){
                bricks += bricksCnt.top();
                bricksCnt.pop();
                ladders --;
            }
        }
        return heights.size() - 1;
    }
};
/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

//O(N*M) O(N*M)
class Solution {
    // up, right, down, left
    vector<vector<int>> directions = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
    };
    set<pair<int, int>> visited;
    void dfs(Robot& robot, int direction, int row, int col){
        robot.clean();
        visited.insert({row, col});
        for(int i = 0; i <directions.size(); i ++){
            int newDirection = (direction + i) % 4;
            int newRow = row + directions[newDirection][0];
            int newCol = col + directions[newDirection][1];
            if(visited.count({newRow, newCol}) || !robot.move()){
                robot.turnRight();
                continue;
            }
            dfs(robot, newDirection, newRow, newCol);
            robot.turnRight();
        }
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
public:
    void cleanRoom(Robot& robot) {
        int direction = 0;
        dfs(robot, direction, 0, 0);
    }
};
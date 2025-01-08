class Solution {
private:
    vector<vector<vector<int>>> dp;
    vector<vector<int>> grid;
    int n;

public:
    int cherryPickup(vector<vector<int>>& grid) {
        this->grid = grid;
        this->n = grid.size();
        this->dp = vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, -1))); 
        return max(0, dpS(0, 0, 0));
    }

    /**
     * Calculates the maximum number of cherries that can be collected by 
     * two robots starting from the given positions.
     *
     * @param row1 Row of the first robot.
     * @param col1 Column of the first robot.
     * @param col2 Column of the second robot. 
     *             (Row of the second robot is calculated as row1 + col1 - col2)
     * @return Maximum number of cherries collected.
     */
    int dpS(int row1, int col1, int col2) {
        int row2 = row1 + col1 - col2; 
        if (row1 >= n || col1 >= n || row2 >= n || col2 >= n || 
                grid[row1][col1] == -1 || grid[row2][col2] == -1) {
            return -1e9; // Invalid state (out of bounds or obstacle)
        } else if (row1 == n - 1 && col1 == n - 1) { 
            return grid[row1][col1]; // Both robots reached the bottom-right corner
        } else if (dp[row1][col1][col2] != -1) {
            return dp[row1][col1][col2]; // Return memoized result
        } else {
            int cherries = grid[row1][col1];
            if (col1 != col2) { // Collect cherry for robot 2 if not on the same cell
                cherries += grid[row2][col2]; 
            }

            int maxCherries = max({
                dpS(row1, col1 + 1, col2 + 1), // Both robots move right
                dpS(row1 + 1, col1, col2 + 1),  // Robot 1 down, Robot 2 right
                dpS(row1, col1 + 1, col2),     // Robot 1 right, Robot 2 down
                dpS(row1 + 1, col1, col2)      // Both robots move down
            });

            dp[row1][col1][col2] = cherries + maxCherries; 
            return cherries + maxCherries;
        }
    }
};
class Solution {
public:
    int minKnightMoves(int x, int y) {
        // Use absolute values due to symmetry
        x = abs(x);
        y = abs(y);

        vector<vector<int>> directions = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1},
                                          {-1, -2}, {-2, -1}, {1, -2}, {2, -1}};

        queue<pair<int, int>> q;
        set<pair<int, int>> visited;
        q.push({0, 0});
        visited.insert({0, 0});

        int moves = 0;

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [currX, currY] = q.front();
                q.pop();

                // Check if we have reached the destination
                if (currX == x && currY == y) {
                    return moves;
                }

                // Explore all possible moves
                for (auto& dir : directions) {
                    int newX = currX + dir[0];
                    int newY = currY + dir[1];

                    // Limit the search space to reasonable bounds
                    if (newX >= -2 && newY >= -2 && newX <= x + 2 && newY <= y + 2 &&
                        visited.find({newX, newY}) == visited.end()) {
                        visited.insert({newX, newY});
                        q.push({newX, newY});
                    }
                }
            }
            moves++;
        }

        return -1; // Should not reach here
    }
};

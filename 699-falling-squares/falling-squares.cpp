class Solution {
public:
    // vector<int> fallingSquares(vector<vector<int>>& positions) {
    //     vector<int> heights, result;
    //     int n = positions.size();
    //     int res = 0;
    //     for(int i = 0; i < n; i ++){
    //         int left = positions[i][0];
    //         int currHeight = positions[i][1];
    //         int right = left + currHeight;
    //         for(int j = 0; j < i; j ++){
    //             int prevLeft = positions[j][0];
    //             int prevSize = positions[j][1];
    //             int prevRight = prevLeft + prevSize;
    //             int prevHeight = heights[j];
    //             if(right > prevLeft && left < prevRight){
    //                 currHeight = max(currHeight + prevSize, prevHeight);
    //             }
    //         }
    //         heights.push_back(currHeight);
    //         res = max(res, currHeight);

    //         result.push_back(res);
    //     }
    //     return result;
    // }
    vector<int> fallingSquares(vector<vector<int>>& positions) {
    vector<int> heights; // To store the heights of squares
    vector<int> result;  // To store the maximum height after each drop
    int maxHeight = 0;

    for (int i = 0; i < positions.size(); i++) {
        int left = positions[i][0];
        int side = positions[i][1];
        int right = left + side;
        int currHeight = side; // Default height when dropped on the ground

        // Check overlap with all previous squares
        for (int j = 0; j < i; j++) {
            int prevLeft = positions[j][0];
            int prevRight = prevLeft + positions[j][1];
            int prevHeight = heights[j];

            // Check if there's an overlap
            if (right > prevLeft && left < prevRight) {
                currHeight = max(currHeight, prevHeight + side);
            }
        }

        heights.push_back(currHeight); // Store the current square's height
        maxHeight = max(maxHeight, currHeight);
        result.push_back(maxHeight); // Update the tallest height
    }

    return result;
}

};
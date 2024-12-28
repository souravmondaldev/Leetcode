class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxLevel = 0, totalWater = 0;

        while (left < right) {
            // Determine the lower height side
            if (height[left] < height[right]) {
                // Update the water level for the left side
                maxLevel = max(maxLevel, height[left]);
                totalWater += maxLevel - height[left];
                cout << left << " : maxLevel :" << maxLevel << " " << height[left] <<endl;
                left++; // Move the left pointer
            } else {
                // Update the water level for the right side
                maxLevel = max(maxLevel, height[right]);
                totalWater += maxLevel - height[right];
                cout << right << " : maxLevel :" << maxLevel << " " << height[right] <<endl;

                right--; // Move the right pointer
            }
        }

        return totalWater;
    }
};

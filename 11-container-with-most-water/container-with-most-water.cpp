class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxWaterArea = INT_MIN;
        while(left < right) {
            int currentWaterArea = min(height[right], height[left]) * (right - left);
            maxWaterArea = max(maxWaterArea, currentWaterArea);
            if(height[left] < height[right])
                left ++;
            else right --;
        }
        return maxWaterArea;
    }
};
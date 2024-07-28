class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> sortedHeights = heights;
        int diff = 0;
        sort(sortedHeights.begin(), sortedHeights.end());
        for(int i = 0; i < heights.size(); i ++){
            diff += (sortedHeights[i] != heights[i]) ? 1 : 0;
        }
        return diff;
    }
};
class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int startPoint = 0, endPoint = 0;
        int totalPoints = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i ++){
            int start = nums[i][0], end = nums[i][1];
            if(i == 0 || endPoint < start){
                totalPoints += end - start + 1;
                
            }
            else if (endPoint >= end){
                continue;
            }
            else totalPoints += end - endPoint;
            startPoint = start;
            endPoint = end;
        }
        return totalPoints;
    }
};
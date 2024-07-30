class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slotsA, vector<vector<int>>& slotsB, int dur) {
        int n = slotsA.size(), m = slotsB.size();
        sort(slotsA.begin(), slotsA.end());
        sort(slotsB.begin(), slotsB.end());
        int i = 0, j = 0;
        while(i < n && j < m){
            int minAvailableStartTimeForBoth = max(slotsA[i][0], slotsB[j][0]);
            int minAvailableEndTimeForBoth = min(slotsA[i][1], slotsB[j][1]);
            int totalAvailableDuration = minAvailableEndTimeForBoth - minAvailableStartTimeForBoth;
            // cout << minAvailableStartTimeForBoth << " : " << minAvailableEndTimeForBoth <<endl;
            if(totalAvailableDuration >= dur){
                return {minAvailableStartTimeForBoth, minAvailableStartTimeForBoth + dur};
            }
            else if(slotsA[i][1] >= slotsB[j][1]){
                j ++;
            }
            else i ++;
        }
        return {};
    }
};
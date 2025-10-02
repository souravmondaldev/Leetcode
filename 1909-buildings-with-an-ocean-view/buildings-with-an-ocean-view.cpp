class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int tallestBuilding = INT_MIN;
        int n = heights.size();
        vector<int> buildingsWithOceanView;
        for(int i = n - 1; i >= 0; i --){
            if(heights[i] > tallestBuilding){
                buildingsWithOceanView.push_back(i);
                tallestBuilding = max(tallestBuilding, heights[i]);
            }
        }
        reverse(buildingsWithOceanView.begin(), buildingsWithOceanView.end());
        return buildingsWithOceanView;
    }
};
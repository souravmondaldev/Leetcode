class Solution {
public:
    int upperBound(vector<int> row){
        int left = 0, right = row.size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(row[mid] < 0){
                right = mid - 1;
            }
            else left = mid + 1;
        }
        cout << left << endl;
        return left;
    }
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i ++){
            // for(int j = 0; j < grid[0].size(); i ++){
                count += grid[0].size() - upperBound(grid[i]);
            // }
        }
        return count;
    }
};
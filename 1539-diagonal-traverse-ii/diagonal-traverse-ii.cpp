class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        if(nums.empty())
            return {};
        queue<pair<int, int>> levels;
        levels.push({0, 0});
        vector<int> ans;
        while(!levels.empty()){
            int size = levels.size();
            for(int i = 0; i < size; i ++){
                auto top = levels.front();
                levels.pop();
                int row = top.first;
                int col = top.second;
                ans.push_back(nums[row][col]);
                if(col == 0 && row + 1 < nums.size()){
                    levels.push({row + 1, col});
                }
                if(col + 1 < nums[row].size()){
                    levels.push({row, col + 1});
                }
            }
        }
        return ans;
    }
};
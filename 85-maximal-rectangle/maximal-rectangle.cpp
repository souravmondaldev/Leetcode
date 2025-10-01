class Solution {
public:
    int largestArea(vector<int> &nums){
        stack<pair<int, int>> st;
        int maxArea = 0;
        int n = nums.size();
        for(int i = 0; i < nums.size(); i ++){
            int currIdx = i;
            while(!st.empty() && st.top().second > nums[i]){
                int prevBarIdx = st.top().first;
                int height = st.top().second;
                currIdx = prevBarIdx;
                st.pop();
                maxArea = max(maxArea, (i-prevBarIdx)*height);
            }
            st.push({currIdx, nums[i]});
        }
        while(!st.empty()){
            int prevBarIdx = st.top().first;
            int height = st.top().second;
            st.pop();
            maxArea = max(maxArea, (n - prevBarIdx) * height);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                grid[i][j] = matrix[i][j] - '0';
                if(i != 0 && grid[i][j] != 0){
                    grid[i][j] += grid[i-1][j];
                }
            }
        }
        int maxArea = 0;
        for(int i = 0; i < n; i ++){
            maxArea = max(maxArea, largestArea(grid[i]));
        }
        return maxArea;
    }
};
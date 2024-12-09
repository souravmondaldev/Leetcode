class Solution {
public:
    int calculateSum(int left, int right, int up, int down, vector<vector<int>>&grid){
        bool expand = true;
        int sum = 0;
        int mid = (left + right) / 2;
        int col1 = mid, col2 = mid;
        for(int row = up ; row <= down; row ++){
            if(col1 == col2)
                sum += grid[row][col1];
            else sum += grid[row][col1] + grid[row][col2];

            if(col1 == left)
                expand = false;
            if(expand){
                col1 -= 1;
                col2 += 1;
            }
            else {
                col1 += 1;
                col2 -= 1;
            }
        }
        return sum;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        unordered_set<int> st;
        priority_queue<int, vector<int>, greater<int>> rombus;
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++){
                int left = j, right = j, down = i;
                while(left >= 0 && right < n && down < m){
                    int sum = calculateSum(left, right, i, down, grid);
                    left -= 1;
                    right += 1;
                    down += 2;
                    if(st.count(sum) == 0)
                        rombus.push(sum);
                    if(rombus.size() > 3)
                        rombus.pop();
                    st.insert(sum);
                }
            }
        }
        int sz = rombus.size();
        vector<int> ans(sz);
        while(!rombus.empty()){
            ans[sz - 1] = rombus.top();
            rombus.pop();
            sz --;
        }

        return ans;
    }
};
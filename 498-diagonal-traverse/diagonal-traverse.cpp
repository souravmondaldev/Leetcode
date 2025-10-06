class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.empty())
            return {};
        int n = mat.size(), m = mat[0].size();
        vector<int> arr(m * n);
        int i = 0;
        int row = 0, col = 0;
        bool up = true;
        while(row < n && col < m){
            // if doigonals is going up
            if(up){
                while(row > 0 && col < m - 1){
                    arr[i++] = mat[row][col];
                    row --;
                    col ++;
                }
                arr[i ++] = mat[row][col];
                if(col == m - 1){
                    row ++;
                }
                else if(row == 0){
                    col ++;
                }
            }
            else{
                while(col > 0 && row < n - 1){
                    arr[i++] = mat[row][col];
                    col --;
                    row ++;
                }
                arr[i ++] = mat[row][col];
                if(row == n - 1){
                    col ++;
                }
                else {
                    row ++;
                }
            }

            //going down
            up = !up;
        }
        return arr;
    }
};
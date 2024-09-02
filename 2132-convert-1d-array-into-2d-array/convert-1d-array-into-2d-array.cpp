class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        //Check for size
        int originalSize = original.size();
        int expectedSize =  m * n;
        if(originalSize != expectedSize)
            return {};
        vector<vector<int>> expected(m, vector<int>(n));
        int idx = 0;
        for(int i = 0 ; i < m; i ++){
            for(int j = 0; j < n; j ++){
                expected[i][j] = original[idx];
                idx ++;
            }
        }
        return expected;
    }
};
#include <vector>
#include <climits>
#include <functional> // For std::function
using namespace std;

class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return dfs(0, n - 1, dp, values);
    }
    int dfs(int i, int j, vector<vector<int>> &dp, vector<int>& values) {
            // Base case: If the range [i, j] cannot form a triangle
            if (j - i < 2) return 0;

            // Return the result if already computed
            if (dp[i][j] != -1) return dp[i][j];

            int tmp = INT_MAX;
            for (int k = i + 1; k < j; ++k) {
                tmp = min(tmp, values[i] * values[k] * values[j] + dfs(i, k, dp, values) + dfs(k, j, dp, values));
            }
            dp[i][j] = tmp;
            return tmp;
        };

};

class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        map<int, int> mp1, mp2;
        int n = grid.size();

        // Populate mp1 with counts of all grid elements
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp1[grid[i][j]]++;
            }
        }

        // Calculate the mid-point index
        int x = n / 2;

        // Populate mp2 with elements in the "Y" pattern
        for (int i = 0; i <= x; i++) {
            mp2[grid[i][i]]++; // Top-left to mid diagonal
        }
        for (int i = n - 1; i >= x; i--) {
            mp2[grid[n - 1 - i][i]]++; // Top-right to mid diagonal
        }
        mp2[grid[x][x]]--; // Adjust for double counting the center cell
        for (int i = x + 1; i < n; i++) {
            mp2[grid[i][x]]++; // Mid column to bottom
        }

        // Adjust mp1 by subtracting counts in mp2
        for (auto& val : mp2) {
            mp1[val.first] -= val.second;
            if (mp1[val.first] < 0) mp1[val.first] = 0; // Prevent negative counts
        }

        // Calculate total sums for mp1 and mp2
        long long sum1 = 0, sum2 = 0;
        for (auto& val : mp1) {
            sum1 += val.second;
        }
        for (auto& val : mp2) {
            sum2 += val.second;
        }

        // Calculate the minimum changes required
        int ans = n * n;

        // Targeting 0
        int n1 = sum1 - mp1[0];
        int n2 = sum2 - max(mp2[1], mp2[2]);
        ans = min(ans, n1 + n2);

        // Targeting 1
        n1 = sum1 - mp1[1];
        n2 = sum2 - max(mp2[0], mp2[2]);
        ans = min(ans, n1 + n2);

        // Targeting 2
        n1 = sum1 - mp1[2];
        n2 = sum2 - max(mp2[0], mp2[1]);
        ans = min(ans, n1 + n2);

        return ans;
    }
};

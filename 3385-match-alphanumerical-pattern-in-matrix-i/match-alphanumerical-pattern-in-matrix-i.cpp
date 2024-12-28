class Solution {
public:
    vector<int> findPattern(vector<vector<int>>& board, vector<string>& pattern) {
        const int m1 = board.size(), n1 = board[0].size(), m2 = pattern.size(), n2 = pattern[0].length();
        for (int i = 0; i + m2 <= m1; ++i) {
            for (int j = 0; j + n2 <= n1; ++j) {
                bool ok = true;
                unordered_map<char, int> have;
                int used = 0;
                for (int x = 0; ok && x < m2; ++x) {
                    for (int y = 0; ok && y < n2; ++y) {
                        const int v = board[i + x][j + y];
                        const char c = pattern[x][y];
                        if (isdigit(c)) {
                            ok = c == v + '0';
                        } else if (have.count(c)) {
                            if (have[c] != v) {
                                ok = false;
                            }
                        } else if (used & (1 << v)) {
                            ok = false;
                        } else {
                            used |= 1 << v;
                            have[c] = v;
                        }
                    }
                }
                if (ok) return {i, j};
            }
        }
        return {-1, -1};
        
    }
};
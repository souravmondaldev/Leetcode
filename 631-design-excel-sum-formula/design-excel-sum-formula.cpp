class Excel {
    vector<vector<int>> grid;
    vector<vector<vector<pair<int, int>>>> dependents; // who depends on me
    vector<vector<vector<pair<int, int>>>> dependencies; // who I depend on

    pair<int, int> parseCell(const string& s) {
        int col = s[0] - 'A';
        int row = stoi(s.substr(1)) - 1;
        return {row, col};
    }

    vector<pair<int, int>> getCells(const string& s) {
        if (s.find(':') == string::npos) return {parseCell(s)};
        auto left = parseCell(s.substr(0, s.find(':')));
        auto right = parseCell(s.substr(s.find(':') + 1));
        vector<pair<int, int>> res;
        for (int r = left.first; r <= right.first; ++r)
            for (int c = left.second; c <= right.second; ++c)
                res.emplace_back(r, c);
        return res;
    }

    void clearDependencies(int r, int c) {
        for (auto& [dr, dc] : dependencies[r][c]) {
            auto& v = dependents[dr][dc];
            v.erase(remove(v.begin(), v.end(), make_pair(r, c)), v.end());
        }
        dependencies[r][c].clear();
    }

    void propagate(int r, int c, int newVal, bool resetDeps) {
        int delta = newVal - grid[r][c];
        grid[r][c] = newVal;
        if (resetDeps) clearDependencies(r, c);
        for (auto& [dr, dc] : dependents[r][c]) {
            int sum = 0;
            for (auto& [sr, sc] : dependencies[dr][dc])
                sum += grid[sr][sc];
            propagate(dr, dc, sum, false);
        }
    }

public:
    Excel(int height, char width) {
        int w = width - 'A' + 1;
        grid = vector<vector<int>>(height, vector<int>(w, 0));
        dependents = vector<vector<vector<pair<int, int>>>>(height, vector<vector<pair<int, int>>>(w));
        dependencies = vector<vector<vector<pair<int, int>>>>(height, vector<vector<pair<int, int>>>(w));
    }

    void set(int row, char column, int val) {
        propagate(row - 1, column - 'A', val, true);
    }

    int get(int row, char column) {
        return grid[row - 1][column - 'A'];
    }

    int sum(int row, char column, vector<string> numbers) {
        int r = row - 1, c = column - 'A';
        clearDependencies(r, c);
        int total = 0;
        for (const string& s : numbers) {
            auto cells = getCells(s);
            for (auto& [sr, sc] : cells) {
                dependencies[r][c].emplace_back(sr, sc);
                dependents[sr][sc].emplace_back(r, c);
                total += grid[sr][sc];
            }
        }
        propagate(r, c, total, false);
        return total;
    }
};

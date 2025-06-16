class Excel {
    vector<vector<int>> grid;
    vector<vector<vector<pair<int, int>>>> cellObservers;
    vector<vector<vector<pair<int, int>>>> observerCells;

    // Convert "A1" to (row=0, col=0)
    pair<int, int> parseCell(const string& s) {
        int col = s[0] - 'A';
        int row = stoi(s.substr(1)) - 1;
        return {row, col};
    }

    // Convert "A1:B2" or "C3" into cell range
    vector<pair<int, int>> getCellsFromRange(const string& s) {
        if (s.find(':') == string::npos) {
            return {parseCell(s)};
        }
        auto p1 = parseCell(s.substr(0, s.find(':')));
        auto p2 = parseCell(s.substr(s.find(':') + 1));
        vector<pair<int, int>> cells;
        for (int i = p1.first; i <= p2.first; ++i) {
            for (int j = p1.second; j <= p2.second; ++j) {
                cells.push_back({i, j});
            }
        }
        return cells;
    }

    void clearDependencies(int r, int c) {
        for (auto& dep : observerCells[r][c]) {
            auto& observers = cellObservers[dep.first][dep.second];
            observers.erase(remove(observers.begin(), observers.end(), make_pair(r, c)), observers.end());
        }
        observerCells[r][c].clear();
    }

    void updateCell(int r, int c, int val, bool override) {
        if (override) clearDependencies(r, c);
        int delta = val - grid[r][c];
        grid[r][c] = val;
        for (auto& observer : cellObservers[r][c]) {
            updateCell(observer.first, observer.second, grid[observer.first][observer.second] + delta, false);
        }
    }

    int setSum(int r, int c, const vector<string>& numbers) {
        clearDependencies(r, c);
        int total = 0;
        for (auto& range : numbers) {
            auto cells = getCellsFromRange(range);
            for (auto& [i, j] : cells) {
                total += grid[i][j];
                cellObservers[i][j].push_back({r, c});
                observerCells[r][c].push_back({i, j});
            }
        }
        updateCell(r, c, total, false);
        return total;
    }

public:
    Excel(int height, char width) {
        int cols = width - 'A' + 1;
        grid = vector<vector<int>>(height, vector<int>(cols));
        cellObservers = vector<vector<vector<pair<int, int>>>>(height, vector<vector<pair<int, int>>>(cols));
        observerCells = vector<vector<vector<pair<int, int>>>>(height, vector<vector<pair<int, int>>>(cols));
    }

    void set(int row, char column, int val) {
        updateCell(row - 1, column - 'A', val, true);
    }

    int get(int row, char column) {
        return grid[row - 1][column - 'A'];
    }

    int sum(int row, char column, vector<string> numbers) {
        return setSum(row - 1, column - 'A', numbers);
    }
};

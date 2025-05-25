class Spreadsheet {
    unordered_map<string, int> sheet;
public:
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        sheet[cell] = value;
    }
    
    void resetCell(string cell) {
        sheet[cell]  = 0;
    }
    bool isNumber(const string& s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
    }
    int getValue(string formula) {
        int idx = formula.find("+");
        string part1 = formula.substr(1, idx - 1);
        string part2 = formula.substr(idx+1);
        cout << part1 << " " << part2 << endl;
        int num1 = isNumber(part1) ? stoi(part1) : sheet[part1];
        int num2 = isNumber(part2) ? stoi(part2) : sheet[part2];
        return num1 + num2;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
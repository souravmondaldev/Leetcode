class Solution {
public:
    void dfs(string &num, int target, int pos, long currVal, long prev,
             string expr, vector<string> &res) {
        if (pos == num.size()) {
            if (currVal == target) res.push_back(expr);
            return;
        }

        for (int i = pos; i < num.size(); i++) {
            // Skip numbers with leading zero
            if (i != pos && num[pos] == '0') break;

            string part = num.substr(pos, i - pos + 1);
            long curNum = stol(part);

            if (pos == 0) {
                // First number, start the expression
                dfs(num, target, i + 1, curNum, curNum, part, res);
            } else {
                dfs(num, target, i + 1, currVal + curNum, curNum, expr + "+" + part, res);
                dfs(num, target, i + 1, currVal - curNum, -curNum, expr + "-" + part, res);
                dfs(num, target, i + 1, currVal - prev + prev * curNum, prev * curNum, expr + "*" + part, res);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num, target, 0, 0, 0, "", res);
        return res;
    }
};

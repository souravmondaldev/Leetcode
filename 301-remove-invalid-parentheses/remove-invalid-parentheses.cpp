class Solution {
public:
    bool isValid(const string &s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                if (count == 0) return false;
                count--;
            }
        }
        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        bool found = false;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                string str = q.front(); q.pop();

                if (isValid(str)) {
                    res.push_back(str);
                    found = true; // found minimum removal
                }

                if (found) continue; // skip generating next level

                for (int j = 0; j < str.size(); j++) {
                    if (!isalpha(str[j]) && str[j] != '(' && str[j] != ')') continue;

                    if (str[j] == '(' || str[j] == ')') {
                        string next = str.substr(0, j) + str.substr(j + 1);
                        if (!visited.count(next)) {
                            q.push(next);
                            visited.insert(next);
                        }
                    }
                }
            }
            if (found) break; // stop BFS at first valid level
        }

        return res;
    }
};

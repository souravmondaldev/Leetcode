class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> netChange;

        // Calculate net balance for each person
        for (auto& transaction : transactions) {
            netChange[transaction[0]] -= transaction[2];
            netChange[transaction[1]] += transaction[2];
        }

        // Collect non-zero balances
        vector<int> balances;
        for (auto& change : netChange) {
            if (change.second != 0) {
                balances.push_back(change.second);
            }
        }

        return recursive(0, balances);
    }

private:
    int recursive(int start, vector<int>& balances) {
        // Skip settled accounts
        while (start < balances.size() && balances[start] == 0) {
            start++;
        }

        // If all accounts are settled
        if (start == balances.size()) {
            return 0;
        }

        int count = INT_MAX;

        // Try settling the current balance with others
        for (int i = start + 1; i < balances.size(); i++) {
            if (balances[start] * balances[i] < 0) { // Opposite signs (can settle)
                // Settle balances[start] with balances[i]
                balances[i] += balances[start];

                // Recurse for the next unsettled account
                count = min(count, 1 + recursive(start + 1, balances));

                // Backtrack
                balances[i] -= balances[start];
            }
        }

        return count;
    }
};

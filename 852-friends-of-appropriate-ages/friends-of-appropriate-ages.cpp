class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> count(121, 0);
        for (int age : ages) count[age]++;
        
        int ans = 0;
        for (int i = 15; i <= 120; i++) { // min age for sending requests is 15
            if (count[i] == 0) continue;
            for (int j = 15; j <= 120; j++) {
                if (count[j] == 0) continue;
                if (j <= 0.5 * i + 7) continue; // rule 1
                if (j > i) continue;            // rule 2
                ans += count[i] * count[j];
                if (i == j) ans -= count[i];   // remove self-request
            }
        }
        return ans;
    }
};

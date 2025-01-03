class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        int netShift = 0;

        for (auto shift : shifts) {
            if (shift[0] == 0) {
                netShift -= shift[1]; // Left shift decreases index
            } else {
                netShift += shift[1]; // Right shift increases index
            }
        }

        // Normalize the net shift
        netShift = ((netShift % n) + n) % n;

        // Apply the net shift
        return s.substr(n - netShift) + s.substr(0, n - netShift);
    }
};

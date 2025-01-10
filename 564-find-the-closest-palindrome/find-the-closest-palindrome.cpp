class Solution {
public:
    long halfPalindrome(long left, bool even) {
        long result = left;
        if (!even) {
            left /= 10;
        }
        while (left) {
            result = result * 10 + left % 10;
            left /= 10;
        }
        return result;
    }

    string nearestPalindromic(string s) {
        int n = s.length();
        int len = n % 2 == 0 ? n / 2  : n / 2 + 1;
        vector<long long> pos;
        long half = stol(s.substr(0, len));
        
        pos.push_back(halfPalindrome(half, n % 2 == 0));
        pos.push_back(halfPalindrome(half + 1, n % 2 == 0));
        pos.push_back(halfPalindrome(half - 1, n % 2 == 0));
        pos.push_back(stol("1" + string(n - 1, '0')) - 1);
        pos.push_back(stol("1" + string(n, '0')) + 1);

        long diff = LONG_MAX, res = 0, sl = stol(s);
        for (auto item : pos) {
            if (item == sl) {
                continue;
            }
            if (abs(item - sl) < diff || (abs(item - sl) == diff && item < res)) {
                diff = abs(item - sl);
                res = item;
            }
        }
        return to_string(res);
    }
};

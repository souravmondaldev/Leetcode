class Solution {
private: 
    long halfPalindrome(long num, bool even){
        long res = num;
        if(!even)
            num = num / 10;
        while(num > 0){
            res = res * 10 + num % 10;
            num = num /10;
        }
        return res;
    }
public:
    string nearestPalindromic(string n) {
        int len = n.length();
        int i = len % 2 == 0 ? len / 2 - 1: len / 2;
        long firstHalf = stol(n.substr(0, i + 1));
        vector<long> possibilities;
        possibilities.push_back((long)pow(10, len - 1) - 1);
        possibilities.push_back((long)pow(10, len) + 1);
        possibilities.push_back(halfPalindrome(firstHalf, len % 2 == 0));
        possibilities.push_back(halfPalindrome(firstHalf - 1, len % 2 == 0));
        possibilities.push_back(halfPalindrome(firstHalf + 1, len % 2 == 0));

        long diff = LONG_MAX, res = 0, nl = stol(n);
        for(auto possible : possibilities){
            if(possible == nl)
                continue;
            if(abs(possible - nl) < diff){
                diff = abs(possible - nl);
                res = possible;
            }
            else if(abs(possible - nl) == diff){
                res = min(res, possible);
            }
        }
        return to_string(res);
    }
};
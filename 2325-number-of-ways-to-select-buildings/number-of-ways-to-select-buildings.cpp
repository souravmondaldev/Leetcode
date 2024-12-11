class Solution {
public:
    long long numberOfWays(string s) {
        long long count = 0;
        int zeroCount = 0, oneCount = 0;
        for(char ch : s){
            zeroCount += ch == '0' ? 1 : 0;
            oneCount += ch == '1' ? 1 : 0;
        }
        int idx = 1, n = s.length() - 1;
        int currZero = 0, currOne = 0;
        for(int i = 0; i <= n; i ++){
            if(s[i]== '1'){
                currOne ++;
                count += (long long)(zeroCount - currZero)  * (currZero);
            }
            else{
                currZero ++;
                count += (long long)(oneCount - currOne)  * (currOne);
            }

        }
        return count;
    }
};
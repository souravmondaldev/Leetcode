class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int totalInvocation = a + b + c;
        int aCount = 0, bCount = 0, cCount = 0;
        string str = "";
        for(int i = 0; i < totalInvocation; i ++){
            if((a >= b && a >= c && aCount < 2) || (a > 0 && (bCount == 2 || cCount == 2))){
                bCount = 0;
                cCount = 0;
                a --;
                str += 'a';
                aCount ++;
            }
            else if((b >= a && b >= c && bCount < 2) || (b > 0 && (aCount == 2 || cCount == 2))){
                aCount = 0;
                cCount = 0;
                b --;
                str += 'b';
                bCount ++;
            }
            else if ((c >= b && c >= a && cCount < 2) || (c > 0 && (bCount == 2 || aCount == 2))){
                bCount = 0;
                aCount = 0;
                c --;
                str += 'c';
                cCount ++;
            }
        }
        return str;
    }
};
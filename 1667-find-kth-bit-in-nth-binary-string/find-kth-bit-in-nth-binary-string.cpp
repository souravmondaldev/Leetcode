class Solution {
private:
    string getReversedInvertedStr(string str){
        string invertedStr = "";
        for(char ch : str){
            invertedStr += ch == '1' ? '0' : '1';
        }
        reverse(invertedStr.begin(), invertedStr.end());
        return invertedStr;
    }
public:
    char findKthBit(int n, int k) {
        char firstBit = '0';
        if(n == 1 || k == 1)
            return firstBit;
        string nthBinaryStr = getNthBinaryStr("0", "0", 0, n);
        return nthBinaryStr[k - 1];
    }
    string getNthBinaryStr(string prevStr, string currStr, int currItr, int n){
        if(currItr == n)
            return currStr;
        string newCurrStr = currStr + "1" + getReversedInvertedStr(currStr);
        return getNthBinaryStr(currStr, newCurrStr, currItr +1, n);
    }
    
    
};
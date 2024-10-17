class Solution {
public:
    int maximumSwap(int num) {
        int maxNum = num;
        string numStr = to_string(num);
        int n = numStr.length();
        for(int i = 1; i < n; i ++){
            for(int j = 0; j < i; j ++){
                swap(numStr[i], numStr[j]);
                maxNum = max(maxNum, stoi(numStr));
                swap(numStr[i], numStr[j]);
            }
        }
        return maxNum;
    }
};
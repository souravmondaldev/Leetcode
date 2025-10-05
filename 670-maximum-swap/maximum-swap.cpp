class Solution {
public:
    int maximumSwap(int num) {
        int maxNum = num;
        string numsStr = to_string(num);
        vector<int> rightmostIndex(10, -1);
        for(int i = 0; i < numsStr.length(); i ++){
            rightmostIndex[numsStr[i] - '0'] = i;
        }
        for(int i = 0; i < numsStr.length(); i ++){
            for(int j = 9; j > numsStr[i] - '0'; j --){
                if(rightmostIndex[j] > i){
                    swap(numsStr[i], numsStr[rightmostIndex[j]]);
                    return stoi(numsStr);
                }
            }
        }

        // int n = numStr.length();
        // for(int i = 1; i < n; i ++){
        //     for(int j = 0; j < i; j ++){
        //         swap(numStr[i], numStr[j]);
        //         maxNum = max(maxNum, stoi(numStr));
        //         swap(numStr[i], numStr[j]);
        //     }
        // }
        // sort(numStr.begin(), numStr.end(), greater<int>());
        return maxNum;
    }
};
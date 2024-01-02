class Solution {
public:
    bool confusingNumber(int n) {
        unordered_map<char, char> invertMap = {{'0', '0'}, {'1', '1'}, {'6', '9'}, {'8', '8'}, {'9', '6'}};
        string rotateNum;
        for(char ch: to_string(n)){
            if(invertMap.find(ch) == invertMap.end())
                return false;
            
            rotateNum += invertMap[ch];
        }
        reverse(rotateNum.begin(), rotateNum.end());

        return stoi(rotateNum) != n;
    }
};
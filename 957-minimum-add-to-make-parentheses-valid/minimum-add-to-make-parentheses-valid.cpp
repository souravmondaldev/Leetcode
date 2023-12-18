class Solution {
public:
    int minAddToMakeValid(string s) {
        int leftBalance = 0, rightBalance = 0;
        for(char ch : s){
            leftBalance += ch == '(' ? 1 : -1;
            if(leftBalance == -1){
                rightBalance ++;
                leftBalance = 0;
            }
        }

        return leftBalance + rightBalance;
    }
};
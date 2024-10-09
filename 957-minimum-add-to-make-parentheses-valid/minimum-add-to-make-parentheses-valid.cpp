class Solution {
public:
    // Time O(N) Space O(1)
    int minAddToMakeValid(string s) {
        int rightOpening = 0, leftOpening = 0;
        for(char ch : s){
            if(ch == '(')
                leftOpening ++;
            else {
                if(leftOpening > 0)
                    leftOpening --;
                else rightOpening ++;
            }
            
        }
        return leftOpening + rightOpening;
    }
};
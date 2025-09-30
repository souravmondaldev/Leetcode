class Solution {
public:
    // O(log10(N)) O(1)
    bool isPalindrome(int x) {
        // string num= to_string(x);
        // int left = 0, right = num.length() - 1;
        // while(left < right){
        //     if(num[left] != num[right])
        //         return false;
        //     left ++;
        //     right --;
        // }
        // return true;
        if(x < 0 || (x%10 == 0 && x > 0))
            return false;
        int reverse = 0;
        while(x > reverse){
            reverse = reverse*10 + x%10 ;
            x = x/10;
        }
        return x == reverse || x == reverse / 10; //In case of odd 123 will be output insteadf of 12321
    }
};
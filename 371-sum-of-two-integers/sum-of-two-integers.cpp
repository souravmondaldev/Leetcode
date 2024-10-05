class Solution {
public:
    int getSum(int a, int b) {
       //Log based approach but can give large numbers, hence not used
    //    double powNum = pow(2, a) * pow(2, b);
    //    return (int)log2(powNum);
        unsigned int carry = b;
        while(b){
            carry = a & b;
            a = a ^ b;
            b = carry << 1;
        }
        return a;
    }
};
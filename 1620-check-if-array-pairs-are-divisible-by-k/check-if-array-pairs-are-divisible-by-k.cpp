class Solution {
public:
    // O(N) O(K) // space can go N in worst case depending on the K
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();

        //Corner case: Check if 1 element
        if(n == 1) return false;
        

        //Get remainder count for each element, module + k will make remaineder positive as numbers can be negative
        //Now handle case if module is 0 ie. perfectly divisble and then cases where I need to pair to x and n-x module
        //Handle the count of module 0 is even to considered as pairs
        vector<int> remainders(k, 0);
        for(int i = 0; i < n; i ++){
            int remainder = (arr[i] % k + k) % k;
            remainders[remainder] ++;
        }
        // If odd count of perfect divisible the false
        if(remainders[0] & 1) return false;

        //Check count for the rem and (k - rem) pairs
        for(int i = 1;  i <= k / 2; i ++){
            if(remainders[i] != remainders[k - i])
                return false;
        } 

        return true;
    }
};
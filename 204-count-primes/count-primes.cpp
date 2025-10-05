class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2){
            return 0;
        }
        vector<bool> primes(n, true);
        for(int p = 2; p <= sqrt(n); p++){
            if(primes[p]){
                for(int j = p*p; j < n; j += p){
                    primes[j] = false;
                }
            }
        }
        int count = 0;
        for(int i = 2; i < n;i ++){
            count += primes[i];
        }
        return count;
    }
};
class Solution {
public:
    vector<bool> fillPrimeNumberInRange(int n){
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }
    vector<vector<int>> findPrimePairs(int n) {
        vector<bool> isPrime = fillPrimeNumberInRange(n);
        vector<vector<int>> primePairs;
        for(int i = 1; i <= n; i ++){
            if(isPrime[n - i] && isPrime[i]){
                isPrime[i] = false;
                primePairs.push_back({i, n - i});
            }
        }

        return primePairs;
    }
};
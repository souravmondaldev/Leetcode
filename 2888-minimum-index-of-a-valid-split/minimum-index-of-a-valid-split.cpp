class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int idx = n - 1;
        unordered_map<int, int> freq;
        int numWithMaxFreq = 0, maxFreq = 0;
        for(int num: nums){
            freq[num] ++;
            if(freq[num] > maxFreq){
                maxFreq = freq[num];
                numWithMaxFreq = num;
            }
        }

        if((n & 1) && maxFreq == n / 2 + 1)
            return -1;
        int countOfMaxFreqNumSoFar = 0;
        for(int i = 0; i < n; i ++){
            if(nums[i] == numWithMaxFreq)
                countOfMaxFreqNumSoFar ++;
            if(countOfMaxFreqNumSoFar > i || i + 1 - countOfMaxFreqNumSoFar < countOfMaxFreqNumSoFar)
                return i;
            
        }
        return idx;
    }
};
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFreq = 0, total = 0;
        for(int num : nums){
            freq[num] ++;
            int currFreq = freq[num];

            if(maxFreq < currFreq){
                maxFreq = currFreq;
                total = maxFreq;
            }
            else if(currFreq == maxFreq)
            {
                total += currFreq;
            }
        }
        return total;
    }
};
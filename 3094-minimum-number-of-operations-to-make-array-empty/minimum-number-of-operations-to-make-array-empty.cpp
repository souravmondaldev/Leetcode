class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> freqs;
        for(int num : nums){
            freqs[num] ++;
        }
        int ans = 0;
        for(auto freq: freqs){
            if(freq.second == 1)
                return -1;
            ans += ceil((double)(freq.second) / 3);
        }

        return ans;
    }
};
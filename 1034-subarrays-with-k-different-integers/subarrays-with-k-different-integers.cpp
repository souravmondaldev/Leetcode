class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return slidingWindow(nums, k) - slidingWindow(nums, k - 1);
    }

    int slidingWindow(vector<int> &nums, int k){
        unordered_map<int, int> freq;
        int left = 0, totalCount = 0;

        for(int right = 0; right < nums.size(); right ++){
            freq[nums[right]] ++;
            while(freq.size() > k){
                freq[nums[left]] --;
                if(freq[nums[left]] == 0)
                    freq.erase(nums[left]);
                left ++;
            }
            totalCount += right - left + 1;
        }
        return totalCount;
    }
};
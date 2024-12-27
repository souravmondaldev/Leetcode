class Solution {
public:
    int nSize;
    vector<int> nums;
    Solution(int n, vector<int>& blacklist) {
        unordered_set<int> blocked;
        n = min(n, 1000005);
        for(int item : blacklist)
            blocked.insert(item);
        for(int i = 0; i < n; i ++){
            if(!blocked.count(i))
                nums.push_back(i);
        }
        nSize = nums.size();
    }
    
    int pick() {
        return nums[rand() % nSize];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
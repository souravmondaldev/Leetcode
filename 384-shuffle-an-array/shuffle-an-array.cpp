class Solution {
private:
    vector<int> original, shuffled;
public:
    Solution(vector<int>& nums) {
        for(int num : nums){
            original.push_back(num);
        }
        shuffled = original;
    }
    
    vector<int> reset() {
        shuffled = original;
        return original;
    }
    
    vector<int> shuffle() {
        int n = shuffled.size();
        for (int i = n - 1; i > 0; --i) {
            int j = rand() % (i + 1); // Random index between 0 and i
            swap(shuffled[i], shuffled[j]);
        }
        return shuffled;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
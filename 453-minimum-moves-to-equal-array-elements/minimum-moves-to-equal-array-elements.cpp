class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int minMove = 0;
        int minElement = *min_element(nums.begin(), nums.end());
        for(int num : nums){
            minMove += num - minElement;
        }
        return minMove;
    }
};
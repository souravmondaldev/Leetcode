class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // time O(N.logN) space O(N)
        priority_queue<int> numsStoredInIncreasingOrder;

        for(int i = 0; i < nums.size(); i ++){
            numsStoredInIncreasingOrder.push(-nums[i]);
            if(numsStoredInIncreasingOrder.size() > k){
                numsStoredInIncreasingOrder.pop();
            }
        }

        return -numsStoredInIncreasingOrder.top();
    }
};
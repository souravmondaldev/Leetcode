class Solution {
public:
    // int findKthLargest(vector<int>& nums, int k) {
    //     // time O(N.logN) space O(N)
    //     priority_queue<int> numsStoredInIncreasingOrder;

    //     for(int i = 0; i < nums.size(); i ++){
    //         numsStoredInIncreasingOrder.push(nums[i]);
    //     }

    //     for(int i = 0; i < k - 1; i ++){
    //         numsStoredInIncreasingOrder.pop();
    //     }

    //     return numsStoredInIncreasingOrder.top();
    // }
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        return nums[k-1];
    }
};
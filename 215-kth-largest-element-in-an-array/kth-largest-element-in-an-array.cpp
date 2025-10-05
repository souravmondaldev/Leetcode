// class Solution {
// public:
//     int findKthLargest(vector<int>& nums, int k) {
//         // time O(N.logk) space O(k)
//         priority_queue<int, vector<int>, greater<int>> numsStoredInIncreasingOrder;

//         for(int i = 0; i < nums.size(); i ++){
//             numsStoredInIncreasingOrder.push(nums[i]);
//             if(numsStoredInIncreasingOrder.size() > k){
//                 numsStoredInIncreasingOrder.pop();
//             }
//         }

//         return numsStoredInIncreasingOrder.top();
//     }
// };

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, k);
    }
    
    int quickSelect(vector<int>& nums, int k) {
        int pivot = nums[rand() % nums.size()];
        
        vector<int> left;
        vector<int> mid;
        vector<int> right;
        
        for (int num: nums) {
            if (num > pivot) {
                left.push_back(num);
            } else if (num < pivot) {
                right.push_back(num);
            } else {
                mid.push_back(num);
            }
        }
        
        if (k <= left.size()) {
            return quickSelect(left, k);
        }
        
        if (left.size() + mid.size() < k) {
            return quickSelect(right, k - left.size() - mid.size());
        }
        
        return pivot;
        
    }
};
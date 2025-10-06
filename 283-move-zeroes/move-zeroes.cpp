class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        // for(int i = 0; i < nums.size(); i ++){
        //     if(nums[i]){
        //         nums[idx ++] = nums[i];
        //     }
        // }
        // for(int i = idx; i < nums.size(); i ++){
        //     nums[i] = 0;
        // }
        int swap_index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                // cout << nums[i] << " " << nums[swap_index] << " Order" <<endl;
                std::swap(nums[i], nums[swap_index]);
                // for (int j = 0; j < nums.size(); j++) {
                //     cout << nums[j] <<" ";
                // }
                // cout << endl;
                
                swap_index++;
            }
        }
    }
};
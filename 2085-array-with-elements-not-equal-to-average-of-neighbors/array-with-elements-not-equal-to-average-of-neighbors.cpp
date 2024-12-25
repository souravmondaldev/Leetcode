class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        int left = 0, right = nums.size() - 1;
        bool rightSide = true;
        while(left <= right){
            if(rightSide){
                ans.push_back(nums[right --]);
            }
            else ans.push_back(nums[left ++]);
            rightSide = !rightSide;
        }   
        return ans;
    }
};
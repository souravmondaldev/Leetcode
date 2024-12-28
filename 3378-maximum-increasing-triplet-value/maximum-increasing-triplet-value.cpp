class Solution {
public:
    int maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> rightMax(n, 0);
        rightMax[n - 1] = nums[n - 1];
        for(int i = n - 2; i >= 0 ; i --){
            rightMax[i] = max(rightMax[i + 1], nums[i]);
        }
        set<int> s;
        int r = 0;
        for(int i = 0; i < n; i ++){
            if(rightMax[i] > nums[i]){
                auto first = s.lower_bound(nums[i]);
                if(first != s.begin()){
                    r= max(r, *prev(first) + rightMax[i] - nums[i]);
                }
            }
            s.insert(nums[i]);
        }
        return r;
    }
};
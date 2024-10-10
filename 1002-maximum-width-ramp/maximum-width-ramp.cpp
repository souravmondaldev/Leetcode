class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> indices(n, 0);
        for(int i = 0; i < n; i ++){
            indices[i] = i;
        }
        sort(indices.begin(), indices.end(), [&](int i , int j){
            return nums[i] == nums[j] ? i < j : nums[i] < nums[j];
        });
        for(int i = 0; i < n; i ++){
            cout << indices[i] << " : " << nums[indices[i]] << endl;
        }
        int maxWidth = 0, minIdx = n;
        for(int i = 0; i < n; i ++){
            maxWidth = max(maxWidth, indices[i] - minIdx);
            minIdx = min(minIdx, indices[i]);
        }

        return maxWidth;
    }
};
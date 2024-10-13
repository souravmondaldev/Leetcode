class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        int left = INT_MAX, right = INT_MIN;
        for(int row = 0; row < nums.size(); row ++){
            left = min(left, nums[row][0]);
            right = max(right, nums[row][0]);
            minHeap.push({nums[row][0], {row, 0}});
        }
        vector<int> range = {left, right};
        int currListIdx = 0;
        while(true){
            auto minElement = minHeap.top();
            minHeap.pop();
            int listIdx = minElement.second.first;
            int currListIdx = minElement.second.second + 1;
            if(currListIdx == nums[listIdx].size())
                return range;
            minHeap.push({nums[listIdx][currListIdx], {listIdx, currListIdx}});
            right = max(right, nums[listIdx][currListIdx]);
            left = minHeap.top().first;
            if(right - left < range[1] - range[0]){
                range = {left, right};
            }
        }
        return range;
    }
};
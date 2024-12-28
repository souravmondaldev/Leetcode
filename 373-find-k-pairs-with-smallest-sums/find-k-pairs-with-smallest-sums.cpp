class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int i = 0, j = 0;
        vector<vector<int>> ans;
        set<pair<int, int>> seen;
        seen.insert({i, j});
        pq.push({nums1[i]+nums2[j], {i, j}});
        for(int idx = 0; idx < k; idx ++){
            auto minInfo = pq.top();
            i = minInfo.second.first, j = minInfo.second.second;
            pq.pop();
            ans.push_back({nums1[i], nums2[j]});
            if(i + 1 < n && !seen.count({i + 1, j})){
                seen.insert({i + 1, j});
                pq.push({nums1[i + 1]+nums2[j], {i + 1, j}});
            }
            if(j + 1 < m && !seen.count({i, j + 1})){
                seen.insert({i, j + 1});
                pq.push({nums1[i]+ nums2[j + 1], {i, j + 1}});
            }
        }
        return ans;
    }
};
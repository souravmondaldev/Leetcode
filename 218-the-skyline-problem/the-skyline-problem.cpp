class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<pair<int, int>> heights;
        multiset<int> pq;
        pq.insert(0);
        int prevMax = 0;
        for(auto building : buildings){
            int start = building[0];
            int end = building[1];
            int height = building[2];
            heights.push_back({start, -height});
            heights.push_back({end, height});
        }
        sort(heights.begin(), heights.end());
        for (auto& height : heights) {
            cout << height.first << " : " << height.second << endl;
            if (height.second < 0) { // Start of building
                pq.insert(-height.second);
            } else { // End of building
                pq.erase(pq.find(height.second));
            }

            // Current max height
            int currMax = *pq.rbegin();
            if (currMax != prevMax) { // Critical point
                ans.push_back({height.first, currMax});
                prevMax = currMax;
            }
        }
        return ans;
        
    }
};
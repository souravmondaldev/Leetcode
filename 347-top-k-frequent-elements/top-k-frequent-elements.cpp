class Solution {
public:
    // vector<int> topKFrequent(vector<int>& nums, int k) {
    //     //BUCKET SORT O(N) O(N)
    //     unordered_map<int, int> counts;
    //     int maxFreq = 0;
    //     //Store the frequencies inside a Map for O(1) access
    //     for(int num : nums){
    //         ++ counts[num];
    //         maxFreq = max(maxFreq, counts[num]);
    //     }

    //     //vector to store numbers with same frequenices

    //     vector<vector<int>> freqCount(maxFreq + 1);
    //     for(auto &count : counts){
    //         freqCount[count.second].push_back(count.first);
    //     }

    //     //get top k elemements based on the count
    //     vector<int> ans;
    //     for(int i = maxFreq; i > 0 && ans.size() < k; i --){
    //         for(int j = 0; j < freqCount[i].size() && ans.size() < k; j ++){
    //             ans.push_back(freqCount[i][j]);
    //         }
    //     }
    //     return ans;

    // }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //Priority queue O(NLogK) O(N + K)
        unordered_map<int, int> counts;
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        int maxFreq = 0;
        //Store the frequencies inside a Map for O(1) access
        for(int num : nums){
            ++ counts[num];
            maxFreq = max(maxFreq, counts[num]);
        }
        for(auto& count: counts){
            pq.push({count.second, count.first});
        }
        for(int i = 0 ; i < k; i ++){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};
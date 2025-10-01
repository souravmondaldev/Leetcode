class Solution {
public:
    // O(NlogN) O(N)
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int globalMin = INT_MAX;
        unordered_map<int, int> counts;
        for(int num : basket1){
            counts[num] ++;
            globalMin = min(globalMin, num);
        }
        for(int num : basket2){
            counts[num] --;
            globalMin = min(globalMin, num);
        }
        vector<int> merge;
        for(auto &[num, count] : counts){
            if(count % 2)
                return -1;
            for(int i = 0; i < abs(count)/2; i ++)
                merge.push_back(num);
        }
        sort(merge.begin(), merge.end());
        long long minCost = 0;
        for(int i = 0; i < merge.size()/2; i ++){
            minCost += min(2 * globalMin, merge[i]);
        }
        return minCost;
    }
};
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int minRound = 0;
        unordered_map<int, int> counts;
        for(int task : tasks){
            counts[task] ++;
        }
        for(auto count : counts){
            if(count.second == 1)
                return -1;
            minRound += ceil((double) count.second/ 3);
        }

        return minRound;
    }
};
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, start = 0, gasSum = 0, costSum  = 0;
        for(int i = 0; i < gas.size(); i ++){
            total += gas[i] - cost[i];
            if(total < 0){
                total = 0;
                start = i + 1;
            }
            gasSum += gas[i];
            costSum += cost[i];
        }
        return gasSum >= costSum ? start : -1;
    }
};
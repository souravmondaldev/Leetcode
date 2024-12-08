class Solution {
private:
    vector<int> prefixSum;
public:
    Solution(vector<int>& w) {
        for(int n : w){
            prefixSum.push_back(prefixSum.empty() ? n : prefixSum.back() + n);
        }
    }
    
    int pickIndex() {
        float randNum = (float) rand()/RAND_MAX;
        float target = prefixSum.back() * randNum;
        for(int i = 0; i < prefixSum.size(); i ++){
            if(target < prefixSum[i]){
                return i;
            }
        }
        return prefixSum.size() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
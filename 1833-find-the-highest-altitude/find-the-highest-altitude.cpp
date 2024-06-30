class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxHeight  = 0, currHeight = 0;
        for(int gain_i : gain){
            currHeight += gain_i;
            maxHeight = max(maxHeight, currHeight);
        }
        return maxHeight;
    }
};
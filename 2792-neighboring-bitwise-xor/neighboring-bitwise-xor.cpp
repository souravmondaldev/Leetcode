class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int xorAll = 0;
        for(int item : derived){
            xorAll ^= item;
        }
        return xorAll == 0;
    }
};
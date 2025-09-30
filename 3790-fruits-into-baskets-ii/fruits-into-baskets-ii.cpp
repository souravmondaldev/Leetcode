class Solution {
public:
    //O(N2) O(1)
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int unsetCount = 0;
        for(int fruit : fruits){
            bool foundBasket = false;
            for(int i = 0; i < baskets.size(); i ++){
                if(baskets[i] >= fruit){
                    baskets[i] = 0;
                    foundBasket = true;
                    break;
                }
            }
            if(!foundBasket)
                unsetCount ++;
        }
        return unsetCount;
    }
};
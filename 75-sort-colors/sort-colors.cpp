class Solution {
public:
    void sortColors(vector<int>& nums) {
        int redCount = 0, whiteCount = 0, blueCount = 0;
        int i = 0;
        for( int num : nums ){
            switch(num) {
                case 0:
                    redCount ++;
                    break;
                case 1:
                    whiteCount ++;
                    break;
                case 2:
                    blueCount ++;
                    break;
            }
        }
        for(int i = 0; i < nums.size(); i ++){
            if(redCount > 0){
                nums[i] = 0;
                redCount --;
                continue;
            }
            if(whiteCount > 0){
                nums[i] = 1;
                whiteCount --;
                continue;
            }
            if(blueCount > 0){
                nums[i] = 2;
                blueCount --;
            }
        }
    }
};
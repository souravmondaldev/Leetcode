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
        while( redCount ){
            nums[i]=0;
            i++;
            redCount --;
        }
        while( whiteCount ){
            nums[i]=1;
            i++;
            whiteCount --;
        }
        while( blueCount ){
            nums[i] = 2;
            i++;
            blueCount --;
        }
    }
};
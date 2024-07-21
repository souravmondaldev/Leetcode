class Solution {
public:
    void flip(vector<int> &arr, int k){
        for(int i = 0; i < k/2 ; i ++){
            int temp = arr[i];
            arr[i] = arr[k - i - 1];
            arr[k - i - 1] = temp;
        }
    }
    vector<int> pancakeSort(vector<int>& arr) {
        int sortedIdx = arr.size();
        vector<int> ans;
        while(sortedIdx > 0){
            int maxNum = INT_MIN, k = 0;
            for(int j = 0; j < sortedIdx; j ++){
                if(arr[j] > maxNum){
                    maxNum = arr[j];
                    k = j;
                }
            }
            flip(arr, k + 1);
            flip(arr, sortedIdx);
            ans.push_back(k+1);
            ans.push_back(sortedIdx);
            sortedIdx --;
        }
        return ans;
    }
};
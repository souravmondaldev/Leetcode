class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // for(int num : arr){
        //     if(num <= k)
        //         k ++;
        //     else break;
        // }
        // return k;
        int left = 0, right = arr.size() - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            int missing = arr[mid] - 1 - mid;
            if( missing < k){
                left = mid + 1;
            }
            else right = mid - 1;
        }
        // cout << arr[right] << endl;
        return left + k;
    }
};
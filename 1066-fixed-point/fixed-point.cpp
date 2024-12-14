class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        int ans = -1;
        while(left <= right){
            int mid = right - (right - left) / 2;
            if(arr[mid] == mid)
                ans = mid, right = mid - 1;
            else if(arr[mid] < mid)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return ans;
    }
};
class Solution {
public:
    int missingElement(vector<int>& arr, int k) {
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = (right - left) / 2 + left;
            int missing = arr[mid] - arr[0] - mid;
            if (missing < k)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return arr[0] + k + right;
    }
};
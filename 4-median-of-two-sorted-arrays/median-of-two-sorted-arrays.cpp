class Solution {
public:
    int p1, p2;
    int getMin(vector<int> &a, vector<int> &b){
        if(p1 < a.size() && p2 < b.size()){
            return a[p1] < b[p2] ? a[p1++] : b[p2++];
        }
        if(p1 < a.size())
            return a[p1 ++];
        return b[p2++];
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        int mid = total / 2;
        if(total % 2){
            for(int i = 0; i < mid; i ++) getMin(nums1, nums2);
            return getMin(nums1, nums2);
        }
        else {
            for(int i = 0; i < mid - 1; i ++) getMin(nums1, nums2);
            int first = getMin(nums1, nums2);
            int second = getMin(nums1, nums2);
            cout << first << " " << second << endl;
            return (first + second)/ 2.0;
        }
    }
};
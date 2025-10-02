class SparseVector {
public:
    vector<int> array;
    SparseVector(vector<int> &nums) {
        array = nums;
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int result = 0;
        for(int i = 0; i < array.size(); i ++){
            result += array[i] * vec.array[i];
        }
        return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
class SparseVector {
public:
    unordered_map<int, int> array;
    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i ++){
            if(nums[i])
                array[i] = nums[i];
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int result = 0;
        for(auto [idx, num] : array){
            if(vec.array.find(idx) != vec.array.end())
                result += num * vec.array[idx];
        }
        return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
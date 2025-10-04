class SparseVector {
public:
    // unordered_map<int, int> array;
    vector<pair<int, int>> indexToNum;
    int binary_search(std::vector<std::pair<int, int>>& index_to_num, int target_index) {
        int left = 0;
        int right = index_to_num.size() - 1;
        while (left <= right) {
            int mid = (right - left)/2 + left;
            if (index_to_num[mid].first == target_index)
                return index_to_num[mid].second;
            if (index_to_num[mid].first < target_index)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return 0;
    }

    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); i ++){
            if(nums[i])
                indexToNum.push_back({i, nums[i]});
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int result = 0;
        for(auto [idx, num] : indexToNum){
            result += num * (binary_search(vec.indexToNum, idx));
        }
        return result;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);
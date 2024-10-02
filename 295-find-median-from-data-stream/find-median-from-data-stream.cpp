// class MedianFinder {
// public:
//     MedianFinder() {
        
//     }
    
//     void addNum(int num) {
        
//     }
    
//     double findMedian() {
        
//     }
// };

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

class MedianFinder {
private:
    vector<int> nums;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //insertion sort using binary search lower bound
        if(nums.empty())
            nums.push_back(num);
        else nums.insert(lower_bound(nums.begin(), nums.end(), num), num);
    }
    
    double findMedian() {
        // sort(nums.begin(), nums.end());
        int n = nums.size();
        return n&1 ? (double)nums[n/2] : (double)(nums[n/2-1] + nums[n/2])/2;
    }
};
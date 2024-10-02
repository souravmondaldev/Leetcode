class MedianFinder {
    // maxHeap minHeap num
    //  2.      0.   2
    //.         2
    //.  2

    //               3
    //.  2,3.        
    //   2.    3.    
    //.              5
    //.  2,5.  3
    //.  2.    3,5
    // 2,3.    5.     
    private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        return maxHeap.size() > minHeap.size() ? (double)maxHeap.top() : (double)(maxHeap.top() + minHeap.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

//Insertion sort O(N) O(N) //PASSED TESTCASES
// class MedianFinder {
// private:
//     vector<int> nums;
// public:
//     MedianFinder() {
        
//     }
    
//     void addNum(int num) {
//         //insertion sort using binary search lower bound
//         if(nums.empty())
//             nums.push_back(num);
//         else nums.insert(lower_bound(nums.begin(), nums.end(), num), num);
//     }
    
//     double findMedian() {
//         // sort(nums.begin(), nums.end());
//         int n = nums.size();
//         return n&1 ? (double)nums[n/2] : (double)(nums[n/2-1] + nums[n/2])/2;
//     }
// };
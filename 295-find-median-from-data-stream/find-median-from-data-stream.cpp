// class MedianFinder {
//     // maxHeap minHeap num
//     //  2.      0.   2
//     //.         2
//     //.  2

//     //               3
//     //.  2,3.        
//     //   2.    3.    
//     //.              5
//     //.  2,5.  3
//     //.  2.    3,5
//     // 2,3.    5.     
//     private:
//     priority_queue<int> maxHeap;
//     priority_queue<int, vector<int>, greater<int>> minHeap;
// public:
//     MedianFinder() {
        
//     }
    
//     void addNum(int num) {
//         maxHeap.push(num);
//         minHeap.push(maxHeap.top());
//         maxHeap.pop();

//         if(minHeap.size() > maxHeap.size()){
//             maxHeap.push(minHeap.top());
//             minHeap.pop();
//         }
//     }
    
//     double findMedian() {
//         return maxHeap.size() > minHeap.size() ? (double)maxHeap.top() : (double)(maxHeap.top() + minHeap.top())/2;
//     }
// };

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

//Insertion sort O(N) O(N) //PASSED TESTCASES
class MedianFinder {
private:
    vector<int> stream;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(stream.size() == 0){
            stream.push_back(num);
        }
        else stream.insert(lower_bound(stream.begin(), stream.end(), num), num);
    }
    
    double findMedian() {
        return stream.size() % 2 ? stream[stream.size()/2] :
            (double)(stream[stream.size()/2 - 1] + stream[stream.size()/2]) / 2;
    }
};
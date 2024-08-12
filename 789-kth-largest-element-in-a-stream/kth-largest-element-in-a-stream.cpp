class KthLargest {
private:
    int K_size;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        K_size = k;
        for(int num: nums){
            int addNum = add(num);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > K_size)
            pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
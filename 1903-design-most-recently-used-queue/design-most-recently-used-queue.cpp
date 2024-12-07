class MRUQueue {
private:
    vector<int> queue;
public:
    MRUQueue(int n) {
        for(int i = 0; i < n; i ++){
            queue.push_back(i + 1);
        }
    }
    
    int fetch(int k) {
        int idx = k - 1;
        int elementToMove = queue[idx];
        queue.erase(queue.begin() + idx);
        queue.push_back(elementToMove);

        return elementToMove;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */
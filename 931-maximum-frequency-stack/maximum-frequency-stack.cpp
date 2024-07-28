class FreqStack {
public:
    priority_queue<pair<int, pair<int, int>>> pq;
    unordered_map<int, int> cnt;
    int time;
    FreqStack() {
        time = 0;
    }
    
    void push(int val) {
        cnt[val] ++;
        time ++;
        pq.push({cnt[val], {time, val}});
    }
    
    int pop() {
        auto topEl = pq.top();
        pq.pop();
        cnt[topEl.second.second] --;
        return topEl.second.second;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
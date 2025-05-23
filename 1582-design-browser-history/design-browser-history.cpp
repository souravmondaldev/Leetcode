class BrowserHistory {
    deque<string> dq;
    int currIndex = 0;
public:
    BrowserHistory(string homepage) {
        dq.push_back(homepage);
        currIndex = 0;
    }
    
    void visit(string url) {
        dq.resize(currIndex + 1);
        dq.push_back(url);
        currIndex++;
    }
    
    string back(int steps) {
        currIndex = max(0,currIndex-steps);
        return dq[currIndex];
    }
    
    string forward(int steps) {
        currIndex = min((int)dq.size() - 1, currIndex + steps);
        return dq[currIndex];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
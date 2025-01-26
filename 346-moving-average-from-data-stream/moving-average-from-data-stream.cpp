class MovingAverage {
    deque<int> window;
    int windowSize;
    double movingAverage;
public:
    MovingAverage(int size) {
        windowSize = size;
        movingAverage = 0.0;
    }
    
    double next(int val) {
        movingAverage += val;
        window.push_back(val);
        if(window.size() == windowSize + 1){
            movingAverage -= window.front();
            window.pop_front();
        }
        return movingAverage / window.size();

    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
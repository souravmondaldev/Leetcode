class MovingAverage {
    deque<int> window;
    int windowSize;
    int movingSum;
public:
    MovingAverage(int size) {
        windowSize = size;
        movingSum = 0;
    }
    
    double next(int val) {
        window.push_back(val);
        movingSum += val;
        if(window.size() > windowSize){
            movingSum -= window.front();
            window.pop_front();
        }
        return (double)movingSum/window.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
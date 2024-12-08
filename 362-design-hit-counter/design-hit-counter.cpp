// class HitCounter {
//     queue<int> hits;
// public:
//     HitCounter() {
        
//     }
    
//     void hit(int timestamp) {
//         hits.push(timestamp);
//     }
    
//     int getHits(int timestamp) {
//         while(!hits.empty()){
//             int diff = timestamp - hits.front();
//             if(diff >= 300) hits.pop();
//             else break;
//         }
//         return hits.size();
//     }
// };

// /**
//  * Your HitCounter object will be instantiated and called as such:
//  * HitCounter* obj = new HitCounter();
//  * obj->hit(timestamp);
//  * int param_2 = obj->getHits(timestamp);
//  */
class HitCounter {
    int total = 0;
    queue<pair<int, int>> hits;
public:
    HitCounter() {
        
    }
    
    void hit(int timestamp) {
        if(hits.empty() || hits.front().first != timestamp)
            hits.push({timestamp, 1});
        else hits.front().second ++;
        total ++;
    }
    
    int getHits(int timestamp) {
        while(!hits.empty()){
            int diff = timestamp - hits.front().first;
            if(diff >= 300) {
                total -= hits.front().second;
                hits.pop();
            }
            else break;
        }
        return total;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */
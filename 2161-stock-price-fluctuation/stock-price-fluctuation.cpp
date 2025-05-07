class StockPrice {
private:
    int latestTime;
    unordered_map<int, int> timestampPriceMap;
    map<int, int> priceFrequency;
public:
    StockPrice() {
        latestTime = 0;
    }
    
    void update(int timestamp, int price) {
        latestTime = max(latestTime, timestamp);
        if(timestampPriceMap.find(timestamp) != timestampPriceMap.end()){
            int oldprice = timestampPriceMap[timestamp];
            priceFrequency[oldprice] --;
            if(priceFrequency[oldprice] == 0){
                priceFrequency.erase(oldprice);
            }
        }
        timestampPriceMap[timestamp] = price;
        priceFrequency[price] ++;
    }
    
    int current() {
        return timestampPriceMap[latestTime];
    }
    
    int maximum() {
        return priceFrequency.rbegin()->first;
    }
    
    int minimum() {
        return priceFrequency.begin()->first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
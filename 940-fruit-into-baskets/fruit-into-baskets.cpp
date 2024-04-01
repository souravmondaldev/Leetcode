class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n <= 2)
            return n;
        int left = 0, right = 0, max_len = 2;
        unordered_map<int, int> buckets;
        while(right < n){
            buckets[fruits[right]] = right;
            right ++;
            if(buckets.size() == 3){
                int min_idx = INT_MAX;
                for(auto &[bucket, fruit_idx]: buckets){
                    min_idx = min(min_idx, fruit_idx);
                }
                buckets.erase(fruits[min_idx]);
                left = min_idx + 1;
            }
            max_len = max(max_len, right - left);
        }

        return max_len;
    }
};
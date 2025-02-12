class Solution {
public:
    int getSumOfDigits(int num){
        int sum = 0;
        while(num){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        priority_queue<pair<int, int>> pq;
        for(int num : nums){
            int sumOfDigits = getSumOfDigits(num);
            pq.push({sumOfDigits, num});
        }
        auto prev = pq.top();
        pq.pop();
        while(!pq.empty()){
            auto curr = pq.top();
            // cout << prev.second << " " << curr.second << endl;
            if(prev.first == curr.first){
                ans = max(ans, prev.second + curr.second);
            }
            prev = curr;
            pq.pop();
        }
        return ans;
    }
};
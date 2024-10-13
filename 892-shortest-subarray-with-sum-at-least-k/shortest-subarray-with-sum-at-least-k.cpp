class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = INT_MAX;
        vector<long long> prefixSum(n, 0);
        for(int i = 0; i < nums.size(); i ++){
            if(i == 0)
                prefixSum[0] = nums[0];
            else prefixSum[i] = prefixSum[i - 1] + nums[i];
            if(prefixSum[i] >= k)
                ans = min(ans, i + 1);
        }
        deque<int> st;
        for(int i = 0; i < prefixSum.size(); i ++){
            while(st.size() && prefixSum[i] - prefixSum[st.front()] >= k){
                ans = min(ans, i - st.front());
                st.pop_front();
            }
            while(st.size() && prefixSum[i] <= prefixSum[st.back()]){
                st.pop_back();
            }
            st.push_back(i);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
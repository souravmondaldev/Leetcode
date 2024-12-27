class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long ans = 0;
        int n = nums1.size();
        vector<int> diff(n);

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }

        int k = k1 + k2;

        vector<long long> freq(100001, 0); // Assumes max difference is <= 100000
        for (int d : diff) {
            freq[d]++;
        }

        for (int i = 100000; i > 0 && k > 0; i--) {
            if (freq[i] == 0) continue;

            long long take = min((long long)freq[i], (long long)k);
            freq[i] -= take;
            freq[i - 1] += take;
            k -= take;
        }

        for (int i = 1; i <= 100000; i++) {
            if (freq[i] > 0) {
                ans += freq[i] * (long long)i * (long long)i;
            }
        }

        return ans;
    }
};

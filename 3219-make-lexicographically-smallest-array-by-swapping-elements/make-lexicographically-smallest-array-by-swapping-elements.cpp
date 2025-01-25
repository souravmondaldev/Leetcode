class UnionFind {
public:
    unordered_map<int, int> parent;
    UnionFind(vector<int>& nums) {
        for (int num : nums) {
            parent[num] = num;
        }
    }

    int find(int a) {
        if (parent[a] != a) {
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }

    void merge(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) {
            parent[rootB] = rootA;
        }
    }
};
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        UnionFind uf(nums);
        vector<int> originalNums = nums;
        sort(nums.begin(), nums.end());

        for(int i = 1; i < n; i ++){
            if(nums[i] - nums[i - 1] <= limit){
                uf.merge(nums[i], nums[i - 1]);
            }
        }
        unordered_map<int, queue<int>> groupToQueue;
        for(int num : nums){
            groupToQueue[uf.find(num)].push(num);
        }
        vector<int> result;
        for(int num : originalNums){
            result.push_back(groupToQueue[uf.find(num)].front());
            groupToQueue[uf.find(num)].pop();
        }
        return result;
    }
};
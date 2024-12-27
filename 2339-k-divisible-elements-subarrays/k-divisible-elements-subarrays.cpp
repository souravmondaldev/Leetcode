class Trie {
public:
    unordered_map<int, Trie*>  next;
};
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        Trie* root = new Trie();
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i ++){
            Trie *temp = root;
            int count = 0;
            for(int j = i; j < n; j ++){
                if(nums[j] % p == 0) count ++;
                if(count > k) break;
                if(temp->next.find(nums[j]) == temp->next.end()){
                    temp->next[nums[j]] = new Trie();
                    ans ++;
                }
                temp = temp->next[nums[j]];
            }
        }
        return ans;
    }
};
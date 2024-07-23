class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        vector<string> ans;
        int minIdxSum = INT_MAX, currIdxSum = 0;
        for(int i = 0; i < list1.size(); i ++){
            mp[list1[i]] = i;
        }
        for(int i = 0; i < list2.size(); i ++){
            auto it = mp.find(list2[i]);
            if(it != mp.end()){
                currIdxSum = it->second + i;
                if(currIdxSum < minIdxSum){
                    minIdxSum  = currIdxSum;
                    ans = {list2[i]};
                }
                else if(currIdxSum == minIdxSum){
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
    }
};
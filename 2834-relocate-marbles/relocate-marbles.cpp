class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        vector<int> finalPos;
        map<int, int> pos;
        for(int i = 0; i < nums.size(); i ++){
            pos[nums[i]] ++;
        }
        for(int i = 0; i < moveFrom.size(); i ++){
            pos[moveFrom[i]] = 0;
            pos[moveTo[i]] ++;
        }
        for(auto p: pos){
            if(p.second)
                finalPos.push_back(p.first);
            // cout << p.second << " ";
        }
        return finalPos;

    }
};
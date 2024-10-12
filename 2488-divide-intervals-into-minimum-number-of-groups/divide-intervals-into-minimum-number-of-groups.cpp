class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> schedules;
        for(vector<int> &interval: intervals){
            schedules[interval[0]] ++;
            schedules[interval[1] + 1] --;
        }
        int groupCount = 0, currentGroupCount = 0;
        for(auto schedule : schedules){
            currentGroupCount += schedule.second;
            groupCount = max(groupCount, currentGroupCount);
        }
        return groupCount;
    }
};
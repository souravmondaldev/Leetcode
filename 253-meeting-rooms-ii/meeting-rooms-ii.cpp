class Solution {
public:
    int minMeetingRooms1(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return 0;
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> scheduler;
        scheduler.push(intervals[0][1]);
        for(int i = 1; i < intervals.size(); i ++){
            int currMeetingEndTime = scheduler.top();
            if(currMeetingEndTime <= intervals[i][0])
                scheduler.pop();
            scheduler.push(intervals[i][1]);
        }
        return scheduler.size();
    }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return 0;
        int maxUsedRoom = 1;
        map<int, int> schedules;
        //mettings event ordering
        for(auto interval : intervals){
            schedules[interval[0]] ++;
            schedules[interval[1]] --;
        }
        int currentUsedRoom = 0;
        for(auto schedule : schedules){
            currentUsedRoom += schedule.second;
            maxUsedRoom = max(maxUsedRoom, currentUsedRoom);
        }
        return maxUsedRoom;
    }
};
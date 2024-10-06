class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)
            return 0;
        int meetingRoomCount = 1;
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
};
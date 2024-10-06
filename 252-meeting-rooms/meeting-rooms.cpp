class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int currentEndTime = 0;
        for(auto interval : intervals){
            // cout << currentEndTime << " ; " << interval[0] << " : " <<interval[1] <<endl;
            if(interval[0] < currentEndTime)
                return false;
            currentEndTime = interval[1];
        }
        return true;
    }
};
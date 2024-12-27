class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long> room(n, 0), roomTime(n, 0);
        for(auto &meeting : meetings){
            int start = meeting[0], end = meeting[1];
            long minAvaialbleTime = LLONG_MAX;
            int minAvailableRoom = 0;
            bool foundUnusedRoom = false;
            for(int i = 0; i < n; i ++){
                if(roomTime[i] <= start){
                    roomTime[i] = end;
                    foundUnusedRoom = true;
                    room[i] ++;
                    break;
                }
                if(minAvaialbleTime > roomTime[i]){
                    minAvaialbleTime = roomTime[i];
                    minAvailableRoom = i;
                }
            }
            if(!foundUnusedRoom){
                    roomTime[minAvailableRoom] += end - start;
                    room[minAvailableRoom] ++;
            }
        }
        int maxMeeting = 0, maxMeetingIdx = 0;
        for(int i = 0; i < n; i ++){
            if(room[i] > maxMeeting){
                maxMeeting = room[i];
                maxMeetingIdx = i;
            }
        }
        return maxMeetingIdx;
    }
};
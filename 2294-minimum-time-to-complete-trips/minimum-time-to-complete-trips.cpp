class Solution {
public:
    bool tripPossible(long long mid, vector<int> &times, int totalTrips){
        long long trips = 0;
        for(int time : times){
            trips += mid / time;
        }
        return trips >= totalTrips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 0;
        long long right = 1LL * *min_element(time.begin(), time.end()) * totalTrips;
        while(left < right){
            long long mid = left + (right - left) /2;
            if(tripPossible(mid, time, totalTrips)){
                right = mid;
            }
            else left = mid + 1;
        }
        return left;
    }
};
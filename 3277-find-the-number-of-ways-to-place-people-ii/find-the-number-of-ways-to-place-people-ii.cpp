class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [&](auto pointA, auto pointB){
            return pointA[0] == pointB[0] ? pointA[1] > pointB[1] : pointA[0] < pointB[0]; 
        });
        int ans = 0;
        int n = points.size();
        // for(auto point : points){
        //     cout << point[0] << " , "<< point[1] <<endl;
        // }
        for(int top_left = 0; top_left < n; top_left ++){
            int maxY = INT_MIN;
            int top_left_x = points[top_left][0];
            int top_left_y = points[top_left][1];
            for(int lower_right = top_left + 1; lower_right < n; lower_right ++){
                int lower_right_x = points[lower_right][0];
                int lower_right_y = points[lower_right][1];
                if(lower_right_y > top_left_y) continue;
                if(lower_right_y > maxY)
                    ans ++;
                if(lower_right_y > maxY)
                    maxY = lower_right_y;
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        unordered_map<string, vector<int>> employeeAccessTimes;
        for(vector<string> &access_time : access_times){
            string employee = access_time[0];
            int time = stoi(access_time[1]);
            employeeAccessTimes[employee].push_back(time);
        }
        for(auto &employeeAccessTime : employeeAccessTimes){
            sort(employeeAccessTime.second.begin(), employeeAccessTime.second.end());
        }

        vector<string> employees;
        for(auto &employeeAccessTime : employeeAccessTimes){
            string employee = employeeAccessTime.first;
            vector<int> employeeAccessTimeList = employeeAccessTime.second;
            for(int timeIdx = 2; timeIdx < employeeAccessTimeList.size(); timeIdx ++){
                if(employeeAccessTimeList[timeIdx] - employeeAccessTimeList[timeIdx - 2] < 100){
                    employees.push_back(employee);
                    break;
                }
            }
        }
        return employees;
    }
};
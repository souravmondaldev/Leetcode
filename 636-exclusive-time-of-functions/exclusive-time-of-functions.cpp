class Solution {
public:
    void processLogs(string log, int &f_id, string &f_type, int &timestamp)
    {
        stringstream ss(log);
        string str = "";
        getline(ss, str, ':');
        f_id = stoi(str);

        getline(ss, str, ':');
        f_type = str;

        getline(ss, str, ':');
        timestamp = stoi(str);
    }

    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int>exe_times(n,0);
        stack<int>st;
        int prevStartTime =0;
        for(auto log : logs)
        {
            int id;
            string type;
            int ts;
            processLogs(log, id, type, ts);

            if(type == "start")
            {
                if(!st.empty()){
                    exe_times[st.top()] += ts - prevStartTime;
                }
                st.push(id);
                prevStartTime = ts;
            }
            else
            {
                int top_id = st.top(); // Retrieve the top element
                st.pop();
                exe_times[id]+=ts - prevStartTime+1;
                prevStartTime = ts+1;
            }
        }
        return exe_times;
        
    }
};
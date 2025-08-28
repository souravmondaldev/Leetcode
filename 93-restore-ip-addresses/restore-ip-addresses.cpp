class Solution {
public:
    vector<string> results;
    vector<string> restoreIpAddresses(string s) {
        vector<string> segments;
        backtrack(s, 0, segments);
        return results;
    }
    string createIpString(vector<string> segments){
        string ip = segments[0];
        for(int i = 1; i < segments.size(); i ++){
            ip += "." + segments[i];
        }
        cout << " IP " << ip << endl;
        return ip;
    }
    bool checkValidSegment(string segment){
         if (segment.size() > 1 && segment[0] == '0') return false;
        int val = stoi(segment);
        return val >= 0 && val <= 255;
    }
    void backtrack(string s, int idx, vector<string> &segments){
        if(segments.size() == 4){
            cout << "Jere" << idx << endl;
            if(idx == s.length()){
                results.push_back(createIpString(segments));
            }
            return;
        }
        for(int i = 1; i < 4; i ++){
            if(i + idx > s.length()) break;

            string segment = s.substr(idx, i);
            if(checkValidSegment(segment)){
                segments.push_back(segment);
                backtrack(s, idx + i, segments);
                segments.pop_back();
            }
        }
    }
};
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(string detail : details){
            count += stoi(detail.substr(11, 2)) > 60 ? 1 : 0;
        }
        return count;
    }
};
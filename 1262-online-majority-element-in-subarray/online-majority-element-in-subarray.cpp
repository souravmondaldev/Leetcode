class MajorityChecker {
private:
    vector<int> voters;
    map<pair<int, int>, pair<int, int>> rangeBaseVoteCountAndWinner;
public:
    MajorityChecker(vector<int>& arr) {
        voters = arr;
    }
    
    int query(int left, int right, int threshold) {
        if(rangeBaseVoteCountAndWinner.find({left, right}) != rangeBaseVoteCountAndWinner.end()){
            if(rangeBaseVoteCountAndWinner[{left, right}].second >= threshold)
                return rangeBaseVoteCountAndWinner[{left, right}].first;
            else return -1;
        }
        int vote = 0, winner = -1;
        for(int i = left; i <= right; i++){
            if(vote == 0){
                winner = voters[i];
            } 
           
            if(winner == voters[i])
                vote ++;
            else vote --;
        }
        int majotVoteCount = 0;
        for(int i = left; i <= right; i++){
            if(voters[i] == winner)
                majotVoteCount ++;
        }
        rangeBaseVoteCountAndWinner[{left, right}] = {winner, majotVoteCount};
        if(majotVoteCount >= threshold)
            return winner;
        else return -1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
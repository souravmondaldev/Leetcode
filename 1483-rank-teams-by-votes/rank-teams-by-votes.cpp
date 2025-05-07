class Solution {
public:
    string rankTeams(vector<string>& votes) {
        string rank = votes[0];
        int n = rank.length();
        vector<vector<int>> teamWithVoteRanks(26, vector<int>(n, 0));
        for(int i = 0; i < votes.size(); i ++){
            for(int j = 0; j < n; j ++){
                teamWithVoteRanks[votes[i][j] - 'A'][j] ++;
            }
        }
        sort(rank.begin(), rank.end(), [&](char a, char b){
            return teamWithVoteRanks[a - 'A'] > teamWithVoteRanks[b - 'A'] ||
                teamWithVoteRanks[a - 'A'] == teamWithVoteRanks[b - 'A'] && a < b;
        });
        return rank;
    }
};
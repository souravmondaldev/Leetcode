class Solution {
private:
    int numberOfSecurityWallsInCurrentRow(string row){
        int numberOfSecurityWalls = 0;
        for(int i = 0; i < row.length(); i ++){
            if(row[i] == '1')
                numberOfSecurityWalls ++;
        }

        return numberOfSecurityWalls;
    }
public:
    int numberOfBeams(vector<string>& bank) {
        int n = bank.size();
        int numberOfBeam = 0;
        int lastSeenSecurityWalls = 0;
        int securityWalls = 0;
        for(int i = 0; i < n;  i++){
            securityWalls = numberOfSecurityWallsInCurrentRow(bank[i]);
            if(securityWalls > 0){
                numberOfBeam += lastSeenSecurityWalls * securityWalls;
                lastSeenSecurityWalls = securityWalls;
            }
        }

        return numberOfBeam;
    }
};
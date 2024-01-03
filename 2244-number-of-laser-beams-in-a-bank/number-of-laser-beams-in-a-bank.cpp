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
        int lastSeenSecurityWallCount = 0;
        vector<int> securityWalls(n);
        for(int i = 0; i < n;  i++){
            securityWalls[i] = numberOfSecurityWallsInCurrentRow(bank[i]);
            // cout << securityWalls[i] << endl;
        }
        for(int i = n - 1; i > 0; i --){
            numberOfBeam += securityWalls[i] * securityWalls[i - 1];
            lastSeenSecurityWallCount = securityWalls[i] == 0 ? lastSeenSecurityWallCount : securityWalls[i];
            if(securityWalls[i] == 0 && securityWalls[i-1]){
                numberOfBeam += securityWalls[i - 1] * lastSeenSecurityWallCount;
                lastSeenSecurityWallCount = 0;
            }
        }

        return numberOfBeam;
    }
};
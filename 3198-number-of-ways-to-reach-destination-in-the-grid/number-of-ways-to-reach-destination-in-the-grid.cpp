class Solution {
public:
    int numberOfWays(int R, int C, int k, vector<int>& source, vector<int>& dest) {
        long MOD = 1e9 + 7;
        long center = 1, samer = 0, samec = 0, other = 0;
        while(k --){
            long prev_center = center;
            long prev_samer = samer;
            long prev_samec = samec;
            long prev_other = other;
            center = (prev_samer * (C - 1) + prev_samec * (R - 1)) % MOD;
            samer = (prev_samer * (C - 2) + prev_center + prev_other * (R - 1)) % MOD;
            samec = (prev_samec * (R - 2) + prev_center + prev_other * (C - 1)) % MOD;
            other = (prev_other * (C - 2) + prev_other * (R - 2) + prev_samec + prev_samer) % MOD;
        }
        if(source[0] == dest[0] && source[1] == dest[1]) return center;
        else if(source[0] == dest[0]) return samer;
        else if(source[1] == dest[1]) return samec;
        else return other;
    }
};

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        unordered_map<char, int> croakCounts;
        int minNumberOfFrogs = -1;
        int minFrog =0, currFrog = 0;
        for(char croak: croakOfFrogs){
            croakCounts[croak] ++;
            if(croak == 'c'){
                currFrog ++;
            }
            else if(croak == 'k'){
                currFrog --;
            }
            minFrog = max(minFrog, currFrog);
            if(croakCounts['c'] < croakCounts['r'] || croakCounts['r'] < croakCounts['o'] ||
            croakCounts['o'] < croakCounts['a'] || croakCounts['a'] < croakCounts['k'])
                return -1;
        }
        
        return currFrog == 0 ? minFrog : -1;
    }
};
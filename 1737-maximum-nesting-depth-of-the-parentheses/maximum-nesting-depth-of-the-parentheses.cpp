class Solution {
public:
    int maxDepth(string s) {
        int max_depth = 0, depth = 0;
        for(char ch: s){
            depth += ch == '(' ? 1: 0;
            depth += ch == ')' ? -1: 0;
            max_depth = max(max_depth, depth);
        }
        return max_depth;
    }
};
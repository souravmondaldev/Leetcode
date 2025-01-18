/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        // Step 1: Find the candidate
        int candidate = 0;
        for (int i = 1; i < n; i++) {
            if (knows(candidate, i)) {
                candidate = i; // Candidate cannot be a celebrity
            }
        }
        
        // Step 2: Validate the candidate
        for (int i = 0; i < n; i++) {
            if (i != candidate) {
                // If the candidate knows `i` or `i` doesn't know the candidate, return -1
                if (knows(candidate, i) || !knows(i, candidate)) {
                    return -1;
                }
            }
        }
        
        return candidate;
    }
};

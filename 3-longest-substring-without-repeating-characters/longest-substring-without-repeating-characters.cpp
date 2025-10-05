class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int answer = 0;
        int pointer = 0;

        for (int i = 0; i < s.size(); i++) {
            // Remove characters until the duplicate is gone
            while (set.find(s[i]) != set.end()) {
                set.erase(s[pointer++]);
            }
            set.insert(s[i]);
            answer = max(answer, (int)set.size());
        }
        return answer;
    }
};
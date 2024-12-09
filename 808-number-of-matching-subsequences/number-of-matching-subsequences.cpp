// class Solution {
// public:
//     int numMatchingSubseq(string s, vector<string>& words) {
//         int count = 0;
//         map<string, bool> mp;
//         for(string word : words){
//             if(mp.find(word) != mp.end()){
//                 if(mp[word] == true)
//                     count ++;
//                 continue;
//             }
//             mp[word] = subseq(s, word);
//             count += (mp[word] == true);
//         }
//         return count;
//     }
//     bool subseq(string s, string word){
//         int idx = 0;
//         for(char ch : s){
//             if(idx < word.length() && word[idx] == ch)
//                 idx ++;
//         }
//         return idx == word.length();
//     }
// };

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        int n_subsequences = 0;
        unordered_map<char, vector<string>> state;

        // Populate the initial state
        for (const string& word : words) {
            state[word[0]].push_back(word.substr(1));
        }

        // Process each character in the string S
        for (char ch : S) {
            vector<string> old_bucket = state[ch];
            state[ch].clear(); // Clear current bucket as we'll process it

            for (const string& suffix : old_bucket) {
                if (suffix.empty()) {
                    n_subsequences++; // Fully matched word
                } else {
                    state[suffix[0]].push_back(suffix.substr(1));
                }
            }
        }

        return n_subsequences;
    }
};

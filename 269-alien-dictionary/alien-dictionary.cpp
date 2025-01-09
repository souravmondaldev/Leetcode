class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.size() == 0) return "";

        unordered_map<char, unordered_set<char>> graph;
        unordered_map<char, int> indegree;
        for(string word : words){
            for(char letter: word){
                indegree[letter] = 0;
            }
        }

        for(int i = 1; i < words.size(); i ++){
            string prevWord = words[i - 1];
            string currentWord = words[i];
            int len = min(prevWord.length(), currentWord.length());
            if(prevWord.substr(0, len) == currentWord.substr(0, len) && prevWord.length() > currentWord.length()) {
                return "";
            }

            
            for(int j = 0; j < len; j++) {
                if(prevWord[j] != currentWord[j]) {
                    if(graph[prevWord[j]].find(currentWord[j]) == graph[prevWord[j]].end()) {
                        graph[prevWord[j]].insert(currentWord[j]);
                        indegree[currentWord[j]]++;
                    }
                    break;
                }

            }
        }

        queue<char> q;
        for(auto el : indegree){
            if(el.second == 0){
                q.push(el.first);
            }
        }
        string ans= "";
        while(!q.empty()){
            char ch = q.front();
            q.pop();
            ans += ch;
            // if(graph[ch].size() != 0){
                for(char el : graph[ch]){
                    indegree[el] --;
                    if(indegree[el] == 0){
                        q.push(el);
                    }
                }
            // }
        }

        return ans.length() == indegree.size() ? ans : "";
    }
};
class Solution {
public:
    string alienOrder(vector<string>& words) {
        if(words.size() == 0)
            return "";
        unordered_map<char, int> indegree;
        unordered_map<char, unordered_set<char>> graph;
        for(int i = 0; i < words.size(); i ++){
            for(int j = 0; j < words[i].size(); j ++){
                indegree[words[i][j]] = 0;
            }
        }
        for(int i = 0; i < words.size() - 1; i ++){
            string curr = words[i];
            string next = words[i + 1];
            //to check lexographic order
            if(curr.size() > next.size() && curr.compare(0, next.length(), next) == 0){
                return "";
            }
            int len = min(curr.length(), next.length());
            for(int j = 0; j < len ; j ++){
                if(curr[j] != next[j]){
                    unordered_set<char> st = graph[curr[j]];
                    if(st.find(next[j]) == st.end()){
                        graph[curr[j]].insert(next[j]);
                        indegree[next[j]] ++;
                    }
                    break;
                }
            }
        }

        queue<char> q;
        for(auto el: indegree){
            if(el.second == 0){
                q.push(el.first);
            }
        }
        string ans= "";
        while(!q.empty()){
            char ch = q.front();
            q.pop();
            ans += ch;
            if(graph[ch].size() != 0){
                for(char el : graph[ch]){
                    indegree[el] --;
                    if(indegree[el] == 0){
                        q.push(el);
                    }
                }
            }
        }
        return ans.length() == indegree.size() ? ans : "";
    }
};
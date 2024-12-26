class Solution {
public:
    unordered_map<string, unordered_map<string, double>> graph;
    unordered_map<string, double> seen;
    bool checkContradictions(vector<vector<string>>& equations, vector<double>& values) {
        for(int i = 0; i < equations.size(); i ++){
            string u = equations[i][0], v = equations[i][1];
            double value = values[i];
            if(u == v && abs(value - 1.0) > 1e-5)
                return true;
            if(graph[u].contains(v) && abs(value - graph[u][v]) > 1e-5)
                return true;
            if(graph[v].contains(u) && abs(1/value - graph[v][u]) > 1e-5)
                return true;
            graph[u][v] = value;
            graph[v][u] = 1/value;
        }
        for(auto &entry : graph){
            string start = entry.first;
            if(!seen.contains(start) && dfs(start, 1.0))
                return true;
        }
        return false;
    }
    bool dfs(string node, double value){
        if(seen.contains(node)){
            return abs(value-seen[node]) > 1e-5;
        }
        seen[node]= value;
        for(auto ngbr : graph[node]){
            string nextNode = ngbr.first;
            double nextValue = ngbr.second;
            if(dfs(nextNode, value * nextValue))
                return true;
        }
        return false;
    }
};
class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        vector<double> answer;
        for(int i = 0; i < equations.size(); i ++){
            string from = equations[i][0];
            string to = equations[i][1];
            double value = values[i];
            graph[from][to] = value;
            graph[to][from] = 1/value;
        }
        for(int i = 0; i < queries.size(); i ++){
            string from = queries[i][0];
            string to = queries[i][1];
            unordered_set<string> visited;
            if (graph.find(from) == graph.end() || graph.find(to) == graph.end()) {
                answer.push_back(-1.0);
            } else {
                unordered_set<string> visited;
                double result = dfs(from, to, 1.0, graph, visited);
                answer.push_back(result);
            }
        }
        return answer;
    }
    double dfs(const string& from, const string& to, double rate, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited) {
        // If the current variable is already visited, return -1.0 to avoid cycles
        if (visited.count(from)) {
            return -1.0;
        }

        // If the target variable is reached, return the accumulated rate
        if (from == to) {
            return rate;
        }

        visited.insert(from);

        // Explore all neighbors
        for (const auto& child : graph[from]) {
            double result = dfs(child.first, to, rate * child.second, graph, visited);
            if (result != -1.0) {
                return result;
            }
        }

        return -1.0; // No valid path found
    }
};
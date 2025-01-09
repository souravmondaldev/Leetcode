class Solution {
public:
    int collectTheCoins(vector<int>& coins, vector<vector<int>>& edges) {
        int n = coins.size();
        int remainingNodes = n;
        vector<unordered_set<int>> graph(n);
        for(auto edge : edges){
            graph[edge[0]].insert(edge[1]);
            graph[edge[1]].insert(edge[0]);
        }

        // find leaf nodes
        queue<int> empty_leafs;
        for(int i = 0; i < n; i ++){
            if(graph[i].size() == 1 && !coins[i]){
                empty_leafs.push(i);
            }
        }

        while(!empty_leafs.empty()){
            int i = empty_leafs.front();
            empty_leafs.pop();
            remainingNodes --;
            for(int nb : vector<int>(graph[i].begin(), graph[i].end())){
                graph[i].erase(nb);
                graph[nb].erase(i);
                if(graph[nb].size() == 1 && !coins[nb]){
                    empty_leafs.push(nb);
                }
            }
        }
        // leafs at distance 2
        queue<int> leafs;
        for(int i = 0; i < n; i ++){
            if(graph[i].size() == 1){
                leafs.push(i);
            }
        }
        for(int trim = 0; trim < 2; trim ++){
            int size = leafs.size();
            for(int i = 0; i < size; i ++){
                int curr = leafs.front();
                leafs.pop();
                remainingNodes --;
                for(int nb : vector<int>(graph[curr].begin(), graph[curr].end())){
                    graph[curr].erase(nb);
                    graph[nb].erase(curr);
                    if(graph[nb].size() == 1){
                        leafs.push(nb);
                    }
                }
            }
        }
        return remainingNodes <= 1 ? 0 : (remainingNodes - 1) * 2;
    }
};
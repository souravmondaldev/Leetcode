class Solution {
public:
    // SPACE O(BUS * STOPS) due to adjList and Time complexity O(BUS * BUS * STOP)  
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        unordered_map<int, vector<int>> routeToBus;
        for(int i = 0; i < routes.size(); i ++){
            for(int route : routes[i]){
                routeToBus[route].push_back(i);
            }
        }
        unordered_set<int> visitedRoute;
        unordered_set<int> visitedBus;
        queue<int> q;
        q.push(source);
        visitedRoute.insert(source);
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz --){
                int currentRoute = q.front();
                q.pop();
                if(currentRoute == target){
                    return level;
                }
                for(int bus : routeToBus[currentRoute]){
                    if(visitedBus.count(bus))
                        continue;
                    visitedBus.insert(bus);
                    for(int route : routes[bus]){
                        if(!visitedRoute.count(route)){
                            visitedRoute.insert(route);
                            q.push(route);
                        }
                    }
                }
            }
            level ++;
        }
        return -1;
    }
};
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target)
            return 0;

        unordered_map<int, vector<int>> adjList;
        unordered_set<int> visBus;
        queue<int> currentBus;
        for(int bus = 0; bus < routes.size(); bus ++){
            for(auto stop: routes[bus]){
                adjList[stop].push_back(bus);
            }
        }
        for(int bus : adjList[source]){
            currentBus.push(bus);
            visBus.insert(bus);
        }
        int stopsVisited = 1; 
        while(!currentBus.empty()){
            int queuedBus = currentBus.size();
            while(queuedBus --){
                int bus = currentBus.front();
                currentBus.pop();
                for(int stop : routes[bus]){
                    if(stop == target){
                        return stopsVisited;
                    }
                    for(int nextBus : adjList[stop]){
                        if(!visBus.count(nextBus)){
                            visBus.insert(nextBus);
                            currentBus.push(nextBus);
                        }
                    }
                    
                }
            }
            stopsVisited++;
        }
        return -1;
    }
};
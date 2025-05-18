class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector <vector <int>> graph(n);
        vector <int> time(n, -1);
        
        for(auto x: edges) { // create adjacency list
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        
        queue <int> q;
        q.push(0);
        time[0] = 0;
        while(q.size()) {
            int node = q.front();
            q.pop();
            
            for(auto child: graph[node]) {
                if(time[child] == -1) { // if not visited.
                    time[child] = time[node] + 1; // calc time for child node
                    q.push(child);
                }
            }
        }
        
        int res = 0;
        for(int i = 1; i<n; i++) 
		{
             int d = time[i];
             int temp = 2*d;
             if(2*d > patience[i])
			 {
                if((2*d)%patience[i]==0)
                temp=4*d-patience[i];
                else
                    temp=4*d-(2*d)%patience[i];   
            }
            
            res = max(res,temp);
			
        }
        return res+1; // since till res time all messages has beed arrived so +1
    }
};
class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegree(n + 1, 0);
        for(auto relation : relations){
            int prev = relation[0], next = relation[1];
            graph[prev].push_back(next);
            indegree[next] ++;
        }
        queue<int> courses;
        int cousesTaken = 0;

        for(int i = 1; i <= n; i ++){
            if(indegree[i] == 0)
                courses.push(i);
        }
        int minSems = 0;
        while(!courses.empty()){
            int size = courses.size();
            while(size --){
                int course = courses.front();
                courses.pop();
                cousesTaken ++;
                for(int nextCourses : graph[course]){
                    indegree[nextCourses] --;
                    if(indegree[nextCourses] == 0){
                        courses.push(nextCourses);
                    }
                }
            }
            minSems ++;
        }
        return cousesTaken == n ?  minSems : -1;
    }
};
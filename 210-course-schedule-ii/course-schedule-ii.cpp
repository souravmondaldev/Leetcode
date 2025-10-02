class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> indegrees(numCourses, 0);

        for (auto& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prereq = prerequisite[1];
            graph[prereq].push_back(course);
            indegrees[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegrees[i] == 0) {
                q.push(i);
            }
        }

        vector<int> finalOrder;
        while (!q.empty()) {
            int currentCourse = q.front();
            q.pop();
            finalOrder.push_back(currentCourse);
            if (graph.count(currentCourse)) {
                for (int nextCourse : graph[currentCourse]) {
                    indegrees[nextCourse]--;
                    if (indegrees[nextCourse] == 0) {
                        q.push(nextCourse);
                    }
                }
            }
        }

        if (finalOrder.size() == numCourses) {
            return finalOrder;
        }
        
        return {}; 
    }
};
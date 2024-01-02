class Solution {
private:
    void removeRobots(vector<int> &healths, stack<int> &st, int idx){
        while(!st.empty()){
            int top = st.top();
            st.pop();

            if(healths[top] > healths[idx]){
                healths[top] -= 1;
                healths[idx] = 0;
                st.push(top);
                return ;
            }
            else if(healths[top] == healths[idx]){
                healths[top] = healths[idx] = 0;
                return ;
            }
            else {
                healths[idx] -= 1;
                healths[top] = 0;
            }
        }
    }
public:
    // Time O(N) Space O(N)
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        stack<int> st;
        int n = positions.size();
        vector<int> idx(n);
        for(int i = 0; i < n; i ++){
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&](int i, int j){
            return positions[i] < positions[j];
        });

        for(int j = 0; j < n; j ++){
            int i = idx[j];
            if(directions[i] == 'L' && st.empty()) 
                continue;
            else if(directions[i] == 'R')
                st.push(i);
            else removeRobots(healths, st, i);
        }
        vector<int> ans;
        for(int health: healths){
            if(health)
                ans.push_back(health);
        }

        return ans;
    }
};
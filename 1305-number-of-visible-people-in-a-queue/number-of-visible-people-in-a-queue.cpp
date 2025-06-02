class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> peopleWihGreterHeight;
        int n = heights.size();
        vector<int> personCountCanSee(n, 0);
        for(int i = n - 1; i >= 0; i --){
            int count = 0;
            while(!peopleWihGreterHeight.empty() && peopleWihGreterHeight.top() < heights[i]){
                count ++;
                peopleWihGreterHeight.pop();
            }
            if(!peopleWihGreterHeight.empty()){
                count ++;
            }
            personCountCanSee[i] = count;
            peopleWihGreterHeight.push(heights[i]);
        }
        return personCountCanSee;
    }
};
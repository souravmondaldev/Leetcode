class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n= heights.size(), ans = 0, i=0;
       
        stack<int> st;
        while(i<n){
            while(!st.empty() and heights[st.top()]> heights[i]){
                int stHeight = st.top();
                int height = heights[stHeight];
                st.pop();
               
                if(st.empty()){
                    ans = max(ans, height*i);
                }
                else ans = max(ans, height * (i-st.top()-1));
            }
            st.push(i);
            i++;
        }
        return ans;
    }
};
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int N = pushed.size(), j = 0;
        stack<int> stack;

        for(int num : pushed){
            stack.push(num);
            while(!stack.empty() && j < N && stack.top() == popped[j]){
                stack.pop();
                j ++;
            }
        }

        return j == N;
    }
};
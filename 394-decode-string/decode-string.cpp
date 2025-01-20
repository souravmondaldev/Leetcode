class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ']') {
                st.push(string(1, s[i])); // Push the character as a string
            } else {
                // Build the string inside the brackets
                string word = "";
                while (!st.empty() && st.top() != "[") {
                    word = st.top() + word;
                    st.pop();
                }
                st.pop(); // Remove the '['

                // Build the number before the brackets
                string num = "";
                while (!st.empty() && isdigit(st.top()[0])) {
                    num = st.top() + num;
                    st.pop();
                }

                // Repeat the word 'num' times
                int n = stoi(num);
                string finalWord = "";
                for (int j = 0; j < n; j++) {
                    finalWord += word;
                }

                st.push(finalWord); // Push the expanded string back to the stack
            }
        }

        // Construct the final result from the stack
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};

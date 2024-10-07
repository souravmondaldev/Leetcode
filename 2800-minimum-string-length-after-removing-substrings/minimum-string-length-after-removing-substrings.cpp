class Solution {
public:
    int minLength(string s) {
        stack<char> q;
        int i = 0, n = s.length();
        while(i < n){
            while(q.size()> 0 && ((q.top() == 'A' && s[i] == 'B') || (q.top() == 'C' && s[i] == 'D'))){
                cout << q.top() << " : " << s[i] << " : " << i << ":" <<q.size() <<endl;
                q.pop();
                i ++;
            }
            if(i >= n)
                    break;
            q.push(s[i]);
            cout << "Inserting " << s[i] <<endl;
            i ++;
        }
        int sz = q.size();
        while(!q.empty()){
            cout << "Q top " <<q.top() <<endl;
            q.pop();
        }
        cout << sz <<endl;
        return sz;
    }
};
class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void merge(int u, int v){
        int parentU = find(u);
        int parentV = find(v);
        if(parentU != parentV){
            parent[parentU] = parentV;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        parent.resize(s.length(), 0);
        for(int i = 0; i < s.length(); i ++){
            parent[i] = i;
        }
        for(auto pair : pairs){
            merge(pair[0], pair[1]);
        }
        unordered_map<int, priority_queue<char, vector<char>, greater<char>>> mp;
        for(int i = 0; i < s.length(); i ++){
            mp[find(i)].push(s[i]);
        } 
        for(int i = 0; i < s.length(); i ++){
            s[i] = mp[find(i)].top();
            mp[find(i)].pop();
        }
        return s;
    }
};
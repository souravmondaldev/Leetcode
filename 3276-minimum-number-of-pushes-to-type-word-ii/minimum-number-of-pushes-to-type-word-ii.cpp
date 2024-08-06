class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(char ch : word)
            freq[ch - 'a'] ++;
        sort(freq.begin(), freq.end(), greater<int>());
        int push = 0;
        for(int i = 0; i < 26; i ++){
            if(freq[i] == 0) break;
            push += (i / 8 + 1) * freq[i];
            cout << i << " : " << (i / 8 + 1) <<endl;
        }
        return push;
    }
};
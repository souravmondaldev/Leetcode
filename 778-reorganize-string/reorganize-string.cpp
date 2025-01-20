class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        priority_queue<pair<int, char>> pq;
        for(int i = 0; i < 26; i ++){
            if(freq[i] > 0){
                pq.push({freq[i], 'a' + i});
            }
        }
        string ans = "";
        while(pq.size() > 1){
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();

            ans += top1.second;
            ans += top2.second;

            top1.first -= 1;
            top2.first -= 1;
            if(top1.first > 0){
                pq.push(top1);
            }
            if(top2.first > 0){
                pq.push(top2);
            }
        }
        if(!pq.empty()){
            if(pq.top().first > 1){
                return "";
            }
            else ans += pq.top().second;
        }
       
        return ans;
    }
};

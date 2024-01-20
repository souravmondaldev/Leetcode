class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> answer;
        for(string word: words){
            string finalWord = "";
            for(char ch: word){
                if(ch == separator){
                    if(finalWord != "")
                        answer.push_back(finalWord);
                    finalWord = "";
                }
                else finalWord += ch;
            }
            if(finalWord != "")
                answer.push_back(finalWord);
        }
        return answer;
    }
};
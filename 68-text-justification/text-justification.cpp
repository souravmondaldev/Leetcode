class Solution {
/*
1. find how many words to fit in a line
2. all words + all word - 1 space < width when extra words exceeds this
3. incremente index by used words
4. take all the word and create a line and push it to answer

start from -1 and then add count of words to know how many space to add
now find remainig space by width - total word + space
equal space and extra space
if last line or single word then add space and equal space to its end
else in between
*/
public:
    vector<string> getCurrentLineWords(int idx, vector<string>&words, int maxWidth){
        vector<string> selectedWords;
        int totalWidth = 0;
        while(idx < words.size() && totalWidth + words[idx].length() <= maxWidth){
            totalWidth += words[idx].length() + 1;
            selectedWords.push_back(words[idx]);
            idx ++;
        }
        return selectedWords;
    }
    string generateLine(vector<string> &curentLineWords, int idx, int maxWidth, int n){
        //need words count - 1 space in between
        //offset is all words with 1 space in between
        int offset = -1;
        for(string word : curentLineWords){
            offset += word.length() + 1;
        }
        string finalStr = "";
        int spaceLeftToAdjust = maxWidth - offset;
        if(curentLineWords.size() == 1){
            return curentLineWords.back() + string(spaceLeftToAdjust, ' ');
        }
        if(idx == n){
            for(int i = 0; i < curentLineWords.size() - 1; i ++){
                finalStr += curentLineWords[i] + " ";
            }
            return finalStr + curentLineWords.back() + string(spaceLeftToAdjust, ' ');
        }
        
        int extraSpaceEach = spaceLeftToAdjust / (curentLineWords.size() - 1);
        int extraSpaceLeft = spaceLeftToAdjust % (curentLineWords.size() - 1);
        int totalPart = curentLineWords.size() - 1;
        for(int i = 0; i < totalPart; i ++){
            curentLineWords[i] += string(extraSpaceEach, ' ');
        }
        for(int i = 0; i < extraSpaceLeft; i ++){
            curentLineWords[i] += string(1, ' ');
        }
        
        for(int i = 0; i < totalPart; i ++){
            finalStr += curentLineWords[i] + " ";
        }
        return finalStr + curentLineWords.back();
        
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
       int n = words.size();
       int idx = 0;
       vector<string> ans;
       while(idx < n){
            vector<string> curentLineWords = getCurrentLineWords(idx, words, maxWidth);
            idx += curentLineWords.size();
            ans.push_back(generateLine(curentLineWords, idx, maxWidth, n));
            // cout << generateLine(curentLineWords, idx, maxWidth, n) << "#" << endl;
       }
       return ans;
    }
};
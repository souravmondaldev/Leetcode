class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> uniqueStore;
        for(string str: arr){
           uniqueStore[str] ++;
        }
        for(string str: arr){
          if(uniqueStore[str] == 1)
            k--;
          if(k == 0)
            return str;
        }
        return "";
    }
};
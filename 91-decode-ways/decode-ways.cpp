class Solution {
public:
    int numDecodings(string s) {
         int n = s.length();
         if(s[0] == '0')
             return 0;
         int one_back = 1, two_back = 1;
         for(int i = 1; i < n; i ++){
             int curr = 0;
             if(s[i] != '0')
                 curr = one_back;
             int currDig = stoi(s.substr(i-1, 2));
            //  cout << one_back << " : "<< two_back << " : " << curr << " " << currDig <<endl;
             if(currDig >= 10 and currDig <= 26)
                    curr += two_back;
             two_back = one_back;
             one_back = curr;

         }
        return one_back;
    }
};
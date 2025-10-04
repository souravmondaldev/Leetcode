class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        if(arr.size() < 2)
            return arr;
        int transPos = -1;
        for(int i = arr.size() - 1; i > 0;  i --){
            if(arr[i - 1] > arr[i]){
                transPos = i - 1;
                break;
            }
        } 
        if(transPos == -1)
            return arr;
        int maxPos  = transPos + 1;
        for(int i = transPos + 1; i < arr.size(); i ++){
            if(arr[i] >= arr[transPos])
                break;
            if(arr[i] > arr[maxPos]){
                maxPos = i;
            }

        }
        cout << transPos << " " << maxPos << " " << endl;
        swap(arr[transPos], arr[maxPos]);
        return arr;
    }
};
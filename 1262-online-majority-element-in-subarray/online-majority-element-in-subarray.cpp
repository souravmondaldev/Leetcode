

class MajorityChecker {
    vector<int>arr;
    map<pair<int,int>,pair<int,int>>cache;
public:    
    MajorityChecker(vector<int>& arr) {
        this->arr=arr;
    }
    int query(int left, int right, int threshold) {
        if(cache.find({left,right})!=cache.end()){
            return cache[{left,right}].first>=threshold?cache[{left,right}].second:-1;
        }
        int element = -1;
        int vote = 0;
        for(int i=left;i<=right;i++){
            if(!vote){
                element = arr[i];
            }
            if(element == arr[i])
                vote++;
            else
                vote--;
        }
        int count = 0;
        for(int i = left; i<=right; i++){
            if(arr[i] == element)
                count++;
        }
        cache[{left,right}] = {count, element};
        return count>=threshold?element:-1;
    }
};

/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left,right,threshold);
 */
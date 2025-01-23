class Solution {
public:
    bool isPossible(vector<int>& nums) {
            map<int,int> m;                        //In map m we will store the frequency of each element in nums.
    map<int,int> m1;                      // Map m1 will store the no. of subsequence ending with nums[i]
    for(int i=0;i<nums.size();i++){
        m[nums[i]]++;
    }
   
    for(auto i :nums){                    // iterate over the nums array
        if(m[i]==0)                         // if nums[i] is already included
            continue;
        m[i]--;                               // decrement the frequency of current element
        if(m1[i-1]>0){                   // 1st check can we include in existing subsequence
            m1[i-1]--;
            m1[i]++;
        }
        else if(m[i+1]!=0 && m[i+2]!=0){          // 2nd check can we form a new subsequence starting with nums[i] and ending with nums[i] + 2
            m[i+1]--;
            m[i+2]--;
            m1[i+2]++;
        }
        else                                                        // otherwise return false
            return false;
    }
    return true;
    }
};
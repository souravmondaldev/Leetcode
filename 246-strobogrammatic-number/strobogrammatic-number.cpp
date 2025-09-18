class Solution {
public:
    bool isStrobogrammatic(string nums) {
        unordered_map<char, char> mirrors = {
            {'0' , '0'},
            {'1', '1'},
            {'6', '9'},
            {'8', '8'},
            {'9', '6'}
        };
        for(int i = 0; i <= nums.length() / 2; i ++){
            char left = nums[i], right = nums[nums.length() - i - 1];
            if(mirrors.find(left) == mirrors.end() || mirrors[left] != right)
                return false;
        }
        return true;
    }
};
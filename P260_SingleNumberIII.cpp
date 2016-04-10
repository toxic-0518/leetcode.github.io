// If we use "xor" operation to iteratively process all the number
// the result will equal to "xor" of two different single numbers
// so the "1" bits in "xor" result indicate that the corresponding 
// bits in two different number are opposite. Thus we can divide
// the numbers into two sets, one of which the correspoding bit of 
// numbers are all "1", and "0" the other. The two singal numbers
// are in two different sets. Thus we append "xor" operation on each
// sets again and find two numbeer respectively. 
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int mask = 0;
        for(int i = 0; i < nums.size(); i++) mask ^= nums[i];
        // find the lowest "1" bits
        // special case: when mask = INT_MIN
        // the mask = -mask = 10000.....0
        // so the result of mask & (-mask) will be 1000....0
        // in which the "1" bit is on highest position. 
        mask = mask & (-mask);
        vector<int> v1, v2;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] & mask) v1.push_back(nums[i]);
            else v2.push_back(nums[i]);
        }
        vector<int> res;
        mask = 0;
        for(int i = 0; i < v1.size(); i++) mask = mask ^ v1[i];
        res.push_back(mask);
        mask = 0;
        for(int i = 0; i < v2.size(); i++) mask = mask ^ v2[i];
        res.push_back(mask);
        return res;
    }
};

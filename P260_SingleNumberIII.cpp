class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int mask = 0;
        for(int i = 0; i < nums.size(); i++) mask ^= nums[i];
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

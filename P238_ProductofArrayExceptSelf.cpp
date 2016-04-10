class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int forward = 1, backward = 1;
        vector<int> res(n, 1);
        for(int i = 0; i < n; i++) {
            res[i] *= forward;
            forward *= nums[i];
            res[n - i - 1] *= backward;
            backward *= nums[n - i - 1];
        }
        return res;
    }
};

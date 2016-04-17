class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max = 0;
        int temp = 0;
        int maxNum = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            temp += nums[i];
            if(temp > max) max = temp;
            if(temp < 0) temp = 0;
            maxNum = std::max(maxNum, nums[i]);
        }
        if(max == 0) return maxNum;
        else return max;
    }
};

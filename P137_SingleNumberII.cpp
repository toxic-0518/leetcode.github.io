//since there are 3n + 1 numbers,
//so the '1' bits on the single number
//must appear 3n + 1 times
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0, two = 0;
        for(int i = 0; i < nums.size(); i++) {
            one = (one ^ nums[i]) & ~two;
            two = (two ^ nums[i]) & ~one;
        }
        return one;
    }
};

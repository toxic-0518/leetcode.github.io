class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        permuteRec(1, nums.size(), nums);
        return permutes;
    }
    void permuteRec(int start, int end, vector<int>& nums) {
        if(start == end) permutes.push_back(nums);
        for(int i = start - 1; i < end; i++) {
            swap(nums[start - 1], nums[i]);
            permuteRec(start + 1, end, nums);
            swap(nums[start - 1], nums[i]);
        }
    }
private:
    vector<vector<int>> permutes;
};

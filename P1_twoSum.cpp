class Solution {
public:
    static bool Greater(pair<int,int> elem1, pair<int,int> elem2) {
        return elem1.first < elem2.first;
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> nums2;
        for(int i = 0; i < nums.size(); i++) {
            pair<int,int> p = make_pair(nums[i], i + 1);
            nums2.push_back(p);
        }
        sort(nums2.begin(), nums2.end(), Greater);
        int j = 0;
        int k = nums2.size() - 1;
        vector<int> result;
        while(1) {
            if(nums2[j].first + nums2[k].first == target) {
                result.push_back(min(nums2[j].second, nums2[k].second));
                result.push_back(max(nums2[j].second, nums2[k].second));
                return result;
            }
            else if(nums2[j].first + nums2[k].first > target) {
                k--;   
            }
            else {
                j++;
            }
        }
    }
};

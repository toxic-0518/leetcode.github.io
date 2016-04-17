class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combine;
        combineRec(0, k, 1, n, combine);
        return combinations;
    }
    void combineRec(int begin, int end, int thres, int n, vector<int>& combination) {
        if((begin != end) && (n < 0)) return;
        else if(begin == end && n > 0) return;
        else if(begin == end && n == 0) combinations.push_back(combination);
        else {
            int j = combination.size();
            for(int i = thres; i <= 9; i++) {
                combination.push_back(i);
                combineRec(begin + 1, end, i + 1, n - i, combination);
                combination.resize(j);
            }
        }
    }
private:
    vector<vector<int>> combinations;
};

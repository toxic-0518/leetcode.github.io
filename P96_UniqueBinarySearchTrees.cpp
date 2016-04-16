// dynamic programming
class Solution {
public:
    int numTrees(int n) {
        vector<int> kinds(n + 1);
        kinds[1] = 1;
        kinds[2] = 2;
        for(int i = 3; i <= n; i++) {
            kinds[i] += kinds[i - 1];
            for(int j = 2; j <= i - 1; j++) {
                kinds[i] += (kinds[j - 1] * kinds[i - j]);
            }
            kinds[i] += kinds[i - 1];
        }
        return kinds[n];
    }
};

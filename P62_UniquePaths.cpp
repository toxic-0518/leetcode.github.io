class Solution {
public:
    int uniquePaths(int m, int n) {
        int paths[101][101];
        for(int i = 1; i <= 100; i++) {
            paths[i][1] = 1;
            paths[1][i] = 1;
        }
        for(int i = 2; i <= m; i++) {
            for(int j = 2; j <= n; j++) {
                paths[i][j] = paths[i][j-1] + paths[i-1][j];
            }
        }
        return paths[m][n];
    }
};

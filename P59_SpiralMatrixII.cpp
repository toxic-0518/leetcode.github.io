class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n);
        for(int i = 0; i < n; i++) {
            matrix[i].resize(n);
        }
        fill(0, n - 1, 1, matrix);
        return matrix;
    }
    
    void fill(int begin, int end, int next, vector<vector<int>>& matrix) {
        if(begin > end) return;
        if(begin == end) {
            matrix[begin][end] = next;
            return;
        }
        else {
            for(int i = begin; i <= end; i++) {
                matrix[begin][i] = next;
                next++;
            }
            for(int i = begin + 1; i <= end; i++) {
                matrix[i][end] = next;
                next++;
            }
            for(int i = end - 1; i >= begin; i--) {
                matrix[end][i] = next;
                next++;
            }
            for(int i = end - 1; i >= begin + 1; i--) {
                matrix[i][begin] = next;
                next++;
            }
        }
        fill(begin + 1, end - 1, next, matrix);
    }
};

// O(n^2) space and O(n^2) time 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> rotate = matrix;
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                rotate[i][j] = matrix[n - j - 1][i];
            }
        }
        matrix = rotate;
    }
};

// O(1) space and O(n^2) time
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix.begin(), matrix.end());
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};

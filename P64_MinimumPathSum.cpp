class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0) return 0;
        vector<vector<int>> minSum(grid.size());
        for(int i = 0; i < grid.size(); i++) {
            minSum[i].resize(grid[0].size());
            if(i == 0) minSum[0][0] = grid[0][0];
            else {
                if(i < grid[0].size()) minSum[0][i] = minSum[0][i-1] + grid[0][i];
                minSum[i][0] = minSum[i-1][0] + grid[i][0];
            }
        }
        for(int i = grid.size(); i < grid[0].size(); i++) {
            minSum[0][i] = minSum[0][i - 1] + grid[0][i];
        }
        
        for(int i = 1; i < grid.size(); i++) {
            for(int j = 1; j < grid[0].size(); j++) {
                minSum[i][j] = min(minSum[i-1][j], minSum[i][j-1]) + grid[i][j]; 
            }
        }
        
        return minSum[grid.size() - 1][grid[0].size() - 1];
    }
};

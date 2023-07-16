class Solution {
public:
    int f(int i, int j,vector<vector<int>> &matrix,vector<vector<int>> &dp) {
        
      if(i==0 && j == 0) return matrix[0][0];
      if(i<0 || j<0) return 1e9;
      if(dp[i][j]!=-1) return dp[i][j];
    
      int up = matrix[i][j] + f(i-1, j, matrix, dp);
      int left = matrix[i][j] + f(i, j-1, matrix, dp);
      
      return dp[i][j] = min(up,left);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1, m-1, grid, dp);
    }
};
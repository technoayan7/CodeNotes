class Solution {
  private: 
    int delRow[4] = {-1, 0, +1, 0};
    int delCol[4] = {0, +1, 0, -1}; 
  void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>&grid) {

      vis[row][col] = 1;
      queue<pair<int,int>> q;
      q.push({row, col});
      int n = grid.size(); 
      int m = grid[0].size(); 
      while(!q.empty()) {
          int row = q.front().first; 
          int col = q.front().second; 
          q.pop(); 
          
          // traverse in the neighbours and mark them if its a land 
          for(int i=0;i<4;i++) {
                  int nrow = row + delRow[i]; 
                  int ncol = col + delCol[i]; 
                  // neighbour row and column is valid, and is an unvisited land
                  if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
                  && grid[nrow][ncol] == '1' && !vis[nrow][ncol] 
                  ) {
                      vis[nrow][ncol] = 1; 
                      q.push({nrow, ncol}); 
                    }
                }
        }
    }
  public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size(); 
        vector<vector<int>> vis(n, vector<int>(m, 0)); 
        int cnt = 0; 
        for(int row = 0; row < n ; row++) {
            for(int col = 0; col < m ;col++) {
                if(!vis[row][col] && grid[row][col] == '1') {
                    bfs(row, col, vis, grid); 
                    cnt++; 
                }
            }
        }
        return cnt; 
    }
};

// TC ~ O(N² + NxMx9), N² for the nested loops, and NxMx9 for the overall DFS of the matrix, 
// that will happen throughout if all the cells are filled with 1.

// SC: O(N²) for visited array max queue space O(N²), If all are marked as 1 then the 
// maximum queue space will be N².
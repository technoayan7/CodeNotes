class Solution {
public:  
    vector<vector<int>> floodFill(vector<vector<int>>& mat, int sr, int sc, int newColor) {
        
        vector<vector<int>> ans = mat; 
        int n = mat.size(), m = mat[0].size();
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int dr[] = {-1, 0, +1, 0};
        int dc[] = {0, +1, 0, -1}; 
    
        int iniColor=mat[sr][sc];
    
        while(!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
             
            //if(mat[r][c] == newColor) continue;
            ans[r][c] = newColor;
            
            for(int i = 0;i<4;i++) {
                int nrow = r + dr[i]; 
                int ncol = c + dc[i]; 

                if(nrow>=0 && nrow<n && ncol>=0 && ncol < m && 
                mat[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                    q.push({nrow, ncol});
                    ans[nrow][ncol] = newColor;
                }
            }
        }
        return ans;
    }
};
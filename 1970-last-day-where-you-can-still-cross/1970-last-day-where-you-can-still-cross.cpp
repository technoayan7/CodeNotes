class Solution {
public:
    int dr[4] = {-1, 0, +1, 0};
    int dc[4] = {0, +1, 0, -1};
    bool canWalk(int row, int col, vector<vector<int>>& cells, int mid) {
        vector<vector<int>> grid(row, vector<int> (col, 0));
        queue<pair<int,int>> q;
        for(int i=0;i<mid;i++) {
            int r = cells[i][0]-1;
            int c = cells[i][1]-1;
            grid[r][c] = 1;
        }
        for(int c=0;c<col;c++) {
            if(grid[0][c] == 0) {
                q.push({0,c});
                grid[0][c] = 1;
            }
        }
        while(!q.empty()) {
            auto [r,c] = q.front();
            q.pop();
            if(r==row-1) return true;
            for(int i=0;i<4;i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 and nr<row and nc>=0 and nc<col and !grid[nr][nc]) {
                    q.push({nr,nc});
                    grid[nr][nc] = 1;
                }
            }
        }
        return false;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int low = 1, high = cells.size(), ans = 0;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(canWalk(row, col, cells, mid)) {
                ans = mid;
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return ans;
    }
};
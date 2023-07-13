class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        
        pq.push({grid[0][0], {0,0}});
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[0][0] = 1;
        int ans = 0;
        
        // if(source.first==destination.first && source.second==destination.second) 
        //     return 0;
            
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        
        while(!pq.empty())
        {
            auto it = pq.top();
            int time = it.first;
            int r = it.second.first;
            int c = it.second.second;
            ans = max(ans, time);
            pq.pop();
            
            if(r==n-1 and c==m-1){
                break;
            }
                
            for(int i = 0; i<4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 and nrow<n and ncol >= 0 and ncol < m and vis[nrow][ncol] == 0)
                {
                    vis[nrow][ncol] = 1;
                    pq.push({grid[nrow][ncol], {nrow,ncol}});
                }
            }
        }
        return ans;
    }
};
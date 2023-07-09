class Solution {
  public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        // {diff, {row, col}}
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        
        int drow[]={-1,0,+1,0};
        int dcol[]={0,+1,0,-1};
        
        while(!pq.empty())
        {
            auto it = pq.top();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            pq.pop();
            
            if(r==n-1 and c==m-1)
                return diff;
                
            for(int i = 0; i<4 ; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 and nrow<n and ncol >= 0 and ncol < m )
                {
                    int newEffort = max(abs(heights[r][c]-heights[nrow][ncol]),diff);
                    if(newEffort < dist[nrow][ncol])
                    {
                        dist[nrow][ncol]=newEffort;
                        pq.push({newEffort,{nrow,ncol}});    
                    }
                }
            }
        }
        return 0;
    }
};
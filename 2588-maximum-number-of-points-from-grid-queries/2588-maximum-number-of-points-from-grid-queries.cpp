class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        //bfs and then cnt+ till your val
        int n = grid.size();
        int m = grid[0].size();
        int q = queries.size();
        vector<pair<int,int>> val;
        for(int i=0;i<q;i++){
            val.push_back({queries[i],i});
        }
        sort(val.begin(),val.end());
        int cnt = 0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        vis[0][0] = 1;
        vector<int> ans(q);

        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};

        auto isvalid = [&](int i,int j,int n,int m){
            if(i <0 || j<0 ||  i>=n || j>=m) return false;
            return true;
        };

        for(int i=0;i<q;i++){
            while(!pq.empty() && pq.top().first < val[i].first){
                auto p = pq.top();
                cnt++;
                pq.pop();
                int r = p.second.first;
                int c = p.second.second;
                for(int k=0;k<4;k++){
                    int nx = dx[k] + r;
                    int ny = dy[k] + c;
                    if(isvalid(nx,ny,n,m) && !vis[nx][ny]){
                        vis[nx][ny] = 1;
                        pq.push({grid[nx][ny],{nx,ny}});
                    }
                }
            }
            ans[val[i].second] = cnt;
        }
        return ans;
    }
};

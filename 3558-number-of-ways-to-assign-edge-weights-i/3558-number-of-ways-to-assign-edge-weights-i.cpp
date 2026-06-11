using ll = long long;
const int M = 1000000007;
class Solution {
public:
    ll chk(ll b, ll e){
        ll r=1;
        while(e){
            if(e&1) r=r*b%M;
            b=b*b%M;
            e>>=1;
        }
        return r;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        auto adj = edges;
        int n = adj.size()+1;
        vector<vector<int>> g(n+1);
        for(auto&it:adj){
            g[it[0]].push_back(it[1]);
            g[it[1]].push_back(it[0]);
        }
        vector<int> d(n+1,-1);
        queue<int>q;
        d[1]=0;
        q.push(1);
        int md=0;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int v:g[u]) if(d[v]==-1){
                d[v]=d[u]+1;
                md = max(md, d[v]);
                q.push(v);
            }
        }
        return chk(2, md-1);
    }
};
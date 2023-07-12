class DSU {
public:
    vector<int> rank, parent, size;
    DSU(int n)
    {
       
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

   
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }    
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
    
    int n=stones.size();
    int maxrow=0;
    int maxcol=0;

    for(auto it:stones){
        maxrow=max(maxrow,it[0]);
        maxcol=max(maxcol,it[1]);
    }

    DSU ds(maxrow+maxcol+1);
    vector<int> vis(maxrow+maxcol+2,0);

    for(auto it:stones){
        int x=it[0];
        int y=maxrow+it[1]+1;

        vis[x]=1;
        vis[y]=1;

        if(ds.findUPar(x)!=ds.findUPar(y)){
            ds.unionBySize(x,y);
        }
        
    }

    int m=vis.size();
    unordered_set<int> st;

    for(int i=0;i<m;i++) {
        if(vis[i]==1){
            st.insert(ds.findUPar(i));
        }
    }
        
    return n-st.size();
    }
};
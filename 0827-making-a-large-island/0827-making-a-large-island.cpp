class DisjointSet {
     public: 
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findParent(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findParent(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int a = findParent(u); 
        int b = findParent(v);
         
        if(a == b) return; 
        if(rank[a] < rank[b]) {
            parent[a] = b; 
        }
        else if(rank[b] < rank[a]) {
            parent[b] = a; 
        }
        else {
            parent[b] = a; 
            rank[a]++; 
        }
    }

    void unionBySize(int u, int v) {
        int a = findParent(u); 
        int b = findParent(v); 
        if(a == b) return; 
        if(size[a] < size[b]) {
            parent[a] = b; 
            size[b] += size[a]; 
        }
        else {
            parent[b] = a;
            size[a] += size[b]; 
        }
    }
}; 

class Solution {
public:
    bool isValid(int row,int col,int n,int m){
        return  row>=0&&row<n&&col>=0&&col<m;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                for(int idx=0;idx<4;idx++){
                    int nrow=row+dr[idx];
                    int ncol=col+dc[idx];
                    if(isValid(nrow,ncol,n,n) && grid[nrow][ncol]==1){
                        int u=n*row+col; //nodeNo
                        int v=n*nrow+ncol; //adjNodeNO
                        ds.unionBySize(u,v);
                    }
                }
            }
        }
        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                int dr[]={-1,0,1,0};
                int dc[]={0,1,0,-1};
                set<int>components;
                for(int idx=0;idx<4;idx++){
                    int nrow=row+dr[idx];
                    int ncol=col+dc[idx];
                    if(isValid(nrow,ncol,n,n) && grid[nrow][ncol]==1){
                        int u=n*row+col; //nodeNo
                        int v=n*nrow+ncol; //adjNodeNO
                        components.insert(ds.findParent(v));
                    }
                }
                int totalSize=0;
                for(auto it:components) {
                    totalSize+=ds.size[it];
                }
                mx=max(mx,totalSize+1);
            }
        }
        for(int cell=0;cell<n*n;cell++){
            mx=max(mx,ds.size[ds.findParent(cell)]);
        }
        return mx;
    }
};
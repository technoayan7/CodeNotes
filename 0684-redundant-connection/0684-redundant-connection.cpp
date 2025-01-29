class DisjointSet {
public:
    vector<int> rank, parent;
    int count = 1;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int findParent(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void Union(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if(u != v){
            if (rank[u] < rank[v]) {
            parent[u] = v;
            } else if (rank[v] < rank[u]) {
                parent[v] = u;
            } else {
                parent[v] = u;
                rank[u]++;
            }
        }
        else {
            count++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n+1);
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            ds.Union(u, v);
            if(ds.count == 2) {
                return {u,v};
            }
        }
        return {};
    }
};
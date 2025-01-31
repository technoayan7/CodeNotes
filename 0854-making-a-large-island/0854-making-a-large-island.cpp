class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int findParent(int node) {
        // Path compression
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void Union(int u, int v) {
        u = findParent(u);
        v = findParent(v);

        if (u != v) {
            // Union by rank
            if (rank[u] < rank[v]) {
                parent[u] = v;
                size[v] += size[u];
            } else if (rank[v] < rank[u]) {
                parent[v] = u;
                size[u] += size[v];
            } else {
                parent[v] = u;
                rank[u]++;
                size[u] += size[v];
            }
        }
    }
};

class Solution {
public:
    bool isValid(int row, int col, int n, int m) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        // Union adjacent 1's
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0)
                    continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                for (int idx = 0; idx < 4; idx++) {
                    int nrow = row + dr[idx];
                    int ncol = col + dc[idx];
                    if (isValid(nrow, ncol, n, n) && grid[nrow][ncol] == 1) {
                        int u = n * row + col;   // nodeNo
                        int v = n * nrow + ncol; // adjNodeNO
                        ds.Union(u, v);
                    }
                }
            }
        }

        int mx = 0;
        // Check each 0 cell
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1)
                    continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, 1, 0, -1};
                set<int> components;
                for (int idx = 0; idx < 4; idx++) {
                    int nrow = row + dr[idx];
                    int ncol = col + dc[idx];
                    if (isValid(nrow, ncol, n, n) && grid[nrow][ncol] == 1) {
                        int v = n * nrow + ncol; // adjNodeNO
                        components.insert(ds.findParent(v));
                    }
                }
                int totalSize = 1; // Start with 1 for the 0 being converted to 1
                for (auto it : components) {
                    totalSize += ds.size[it];
                }
                mx = max(mx, totalSize);
            }
        }

        // Check the size of the largest island without flipping any 0
        for (int cell = 0; cell < n * n; cell++) {
            if (grid[cell / n][cell % n] == 1) {
                mx = max(mx, ds.size[ds.findParent(cell)]);
            }
        }

        return mx;
    }
};

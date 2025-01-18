class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        const int inf = 1e9;

        using ti = tuple<int, int, int>;

        int m = grid.size(), n = grid[0].size();
        priority_queue<ti, vector<ti>, greater<ti>> pq;
        pq.emplace(0, 0, 0);
        vector<vector<int>> dist(m, vector<int>(n, inf));
        dist[0][0] = 0;

        while (!pq.empty()) {
            auto [cost, x, y] = pq.top();
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int newx = x + dx[i], newy = y + dy[i];
                if (newx >= 0 && newx < m && newy >= 0 && newy < n) {
                    int newcost = cost + (i == grid[x][y] - 1 ? 0 : 1);
                    if (newcost < dist[newx][newy]) {
                        dist[newx][newy] = newcost;
                        pq.emplace(newcost, newx, newy);
                    }
                }
            }
        }

        return dist[m - 1][n - 1];
    }
};
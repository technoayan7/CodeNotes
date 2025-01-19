#define ppi pair<int, pair<int, int>>
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int res = 0, n = heightMap.size(), m = heightMap[0].size();
        using tp = tuple<int, int, int>;
        priority_queue<tp, vector<tp>, greater<tp>> pq;
        vector<vector<int>> vis(n, vector<int> (m));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i == 0 or j == 0 or i == n - 1 or j == m - 1) {
                    pq.emplace(heightMap[i][j], i, j);
                    vis[i][j] = 1;
                }
            }
        }

        int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
        int total = 0, maxH = 0;

        while(!pq.empty()) {
            auto [h, x, y] = pq.top();
            pq.pop();

            maxH = max(maxH, h);

            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx > 0 and ny > 0 and nx < n and ny < m and !vis[nx][ny]) {
                    pq.emplace(heightMap[nx][ny], nx, ny);
                    vis[nx][ny] = 1;

                    if(heightMap[nx][ny] < maxH) 
                        total += maxH - heightMap[nx][ny];
                }
            }
        }

        return total;
    }
};
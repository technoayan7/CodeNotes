class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        vector<vector<int>> grid(n, vector<int>(n, 1e7));

        for (auto pre : prerequisites) {
            grid[pre[0]][pre[1]] = 1;
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
                }
            }
        }

        vector<bool> ans;
        for (auto it : queries) {
            int query = grid[it[0]][it[1]];
            if (query != 1e7)
                ans.push_back(true);
            else
                ans.push_back(false);
        }

        return ans;
    }
};

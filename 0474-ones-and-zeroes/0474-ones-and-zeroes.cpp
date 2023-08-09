class Solution {
public:
    int findMaxForm(vector<string>& s, int m, int n) {
        vector<vector<vector<int>>> dp(s.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return f(s, m, n, 0, dp); 
    }

    int f(vector<string>& s, int m, int n, int i, vector<vector<vector<int>>>& dp) {
        if (m == 0 && n == 0) return 0;
        if (i == s.size()) return 0;
        if (dp[i][m][n] != -1) return dp[i][m][n];

        int ones = count(s[i].begin(), s[i].end(), '1');
        int zeros = s[i].size() - ones;
        int take = 0;
        if (m >= zeros && n >= ones)
            take = 1 + f(s, m - zeros, n - ones, i + 1, dp);
        int dontTake = f(s, m, n, i + 1, dp);

        return dp[i][m][n] = max(take, dontTake);
    }
};
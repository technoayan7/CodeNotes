class Solution {
public:

    int f(int i, int lastcp, int n, vector<vector<int>> &dp) {
    if (i == n) return 0;
    if (i + lastcp > n) return 1e9;
    
    if (dp[i][lastcp] != -1) return dp[i][lastcp];
    int cp = 2 + f(i + i, i, n, dp);
    int p = 1 + f(i + lastcp, lastcp, n, dp);

    return dp[i][lastcp] = min(cp, p);
    }

    int minSteps(int n) {
        if (n == 1) return 0;
        vector<vector<int>> dp(n + 1, vector<int>(n, -1));
        return f(2, 1, n, dp) + 2;
    }

};
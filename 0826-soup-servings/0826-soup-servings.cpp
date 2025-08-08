class Solution {
public:
    vector<pair<int, int>> pairs = {{100, 0}, {75, 25}, {50, 50}, {25, 75}};
    double solve(int A, int B, vector<vector<double>> &dp) {
        if(A<=0 and B<=0) return 0.5;
        if(A<=0) return 1.0;
        if(B<=0) return 0.0;

        if(dp[A][B] != -1.0) return dp[A][B];
        double probability = 0.0;
        for(auto it: pairs) {
            int takeA = it.first;
            int takeB = it.second;
            probability += solve(A-takeA, B-takeB, dp);
        }
        return dp[A][B] = probability*0.25;
    }
    double soupServings(int n) {
        if(n > 5000) return 1;
        vector<vector<double>> dp(n+1, vector<double>(n+1, -1));
        return solve(n, n, dp);
    }
};
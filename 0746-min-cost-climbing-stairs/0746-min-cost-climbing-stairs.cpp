class Solution {
public:
    int rob(vector<int>& cost, vector<int>& dp, int i) {
        if(i >= cost.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int notTake = cost[i] + rob(cost, dp, i+1);
        int take = cost[i] + rob(cost, dp, i+2);
        return dp[i] = min(notTake, take);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        int ans1 = rob(cost, dp, 0);
        int ans2 = rob(cost, dp, 1);
        if(n == 1) return cost[0];
        return min(ans1, ans2);
    }
};
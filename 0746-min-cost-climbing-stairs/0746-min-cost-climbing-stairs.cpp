class Solution {
public:
    int rob1(vector<int>& cost, vector<int>& dp1, int i) {
        if(i >= cost.size()) return 0;
        if(dp1[i] != -1) return dp1[i];
        int notTake = cost[i] + rob1(cost, dp1, i+1);
        int take = cost[i] + rob1(cost, dp1, i+2);
        return dp1[i] = min(notTake, take);
    }
    int rob2(vector<int>& cost, vector<int>& dp2, int i) {
        if(i >= cost.size()) return 0;
        if(dp2[i] != -1) return dp2[i];
        int notTake = cost[i] + rob1(cost, dp2, i+1);
        int take = cost[i] + rob1(cost, dp2, i+2);
        return dp2[i] = min(notTake, take);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int ans1 = rob1(cost, dp1, 0);
        int ans2 = rob2(cost, dp2, 1);
        if(n == 1) return cost[0];
        return min(ans1, ans2);
    }
};
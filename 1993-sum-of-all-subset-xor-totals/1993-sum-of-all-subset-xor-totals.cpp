class Solution {
public:
    int dfs(vector<int>& nums, int i, int ans, vector<vector<int>> &dp) {
        if (i == nums.size()) {
            return ans;
        }

        if(dp[i][ans] != -1) return dp[i][ans];

        int take = dfs(nums, i + 1, ans ^ nums[i], dp);
        int notTake = dfs(nums, i + 1, ans, dp);
        return dp[i][ans] = take + notTake;
    }
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(1e5, -1));
        return dfs(nums, 0, 0, dp);
    }
};
class Solution {
public:
    int solve(int i, vector<int>& nums, int r ,vector<vector<int>> &dp){
        if (i == nums.size()) {
            return (r == 0) ? 0 : INT_MIN;
        }

        if (dp[i][r] != -1) return dp[i][r];

        int notTake = 0 + solve(i + 1, nums, r, dp);
        int take = nums[i] + solve(i + 1, nums, (r + nums[i]) % 3, dp);

        return dp[i][r] = max(take, notTake);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
		vector<vector<int>> dp(n,vector<int>(3,-1));  
		return solve(0,nums,0,dp);
    }
};

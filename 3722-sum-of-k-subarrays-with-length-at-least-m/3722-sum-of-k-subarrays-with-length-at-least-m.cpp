class Solution {
public:
    int maxSum(vector<int>& nums, int k, int m) {
        int n = nums.size();
        
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        const long long NEG = -1e18;
        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, NEG));

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; j++) {
            vector<long long> best(n + 1, NEG);
            best[0] = dp[j - 1][0] - prefix[0];

            for (int i = 1; i <= n; i++) {
                best[i] = max(best[i - 1], dp[j - 1][i] - prefix[i]);
            }

            for (int i = 1; i <= n; i++) {
                dp[j][i] = dp[j][i - 1];
                if (i >= m) {
                    dp[j][i] = max(dp[j][i], prefix[i] + best[i - m]);
                }
            }
        }

        return dp[k][n];
    }
};

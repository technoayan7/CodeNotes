class Solution {
public:
    int f(int i, int buy, vector<int> &prices, int n, int fee, vector<vector<int>>&dp)
    {
        if(i >= n) return 0;

        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;

        if(buy)
        {
            int Buy = (-prices[i] + f(i+1, 0, prices, fee, n, dp));
            int skip = 0 + f(i+1, 1, prices, fee, n, dp);
            profit = max(Buy,skip);
        }
        else
        {
            int Sell = (prices[i] - fee + f(i+1, 1, prices, fee, n, dp));
            int skip = 0 + f(i+1, 0, prices, fee, n, dp);
            profit=max(Sell,skip);
        }
        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2, 0));
        dp[n][0] = dp[n][1] = 0;
        for(int i = n-1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if(buy == 1)
                {
                    int Buy = -prices[i] + dp[i+1][0];
                    int skip = 0 + dp[i+1][1];
                    profit = max(Buy,skip);
                }
                else
                {
                    int Buy = prices[i] - fee + dp[i+1][1];
                    int skip = 0 + dp[i+1][0];
                    profit = max(Buy,skip);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};
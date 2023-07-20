class Solution {
public:
    int solve(int i, int buy, vector<int>&prices,vector<vector<int>>&dp)
    {
        if(i==prices.size()) return 0;
        
        if(dp[i][buy]!=-1) return dp[i][buy];
        int profit=0;
        
        if(buy)
        {
            int Buy = (-prices[i]+solve(i+1,0,prices,dp));
            int skip = 0+solve(i+1,1,prices,dp);
            profit = max(Buy,skip);
        }
        else
        {
            int Sell = (prices[i]+solve(i+1,1,prices,dp));
            int skip = 0+solve(i+1,0,prices,dp);
            profit=max(Sell,skip);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0] = dp[n][1] = 0;
        int profit = 0;
        for(int i = n-1; i >= 0; i--) {
            for(int j = 0; j <= 1; j++) {
                int profit = 0;
                if(j)
                {
                    int Buy = -prices[i] + dp[i+1][0];
                    int skip = 0 + dp[i+1][1];
                    profit = max(Buy,skip);
                }
                else
                {
                    int Buy = prices[i] + dp[i+1][1];
                    int skip = 0 + dp[i+1][0];
                    profit = max(Buy,skip);
                }
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }
};



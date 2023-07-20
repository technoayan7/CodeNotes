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
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return solve(0,1,prices,dp);
    }
};
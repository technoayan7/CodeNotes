class Solution {
public:
    int f(int i, int buy, int c, vector<int>&prices, vector<vector<vector<int>>> &dp) {
        if(c == 0 || i == prices.size()) return 0;

        if(dp[i][buy][c] != -1) return dp[i][buy][c];
        int profit=0;

        if(buy)
        {
            int Buy = (-prices[i] + f(i+1, 0, c, prices, dp));
            int skip = (0 + f(i+1, 1, c, prices, dp));
            profit = max(Buy, skip);
        } 
        else
        {
            int Sell = (prices[i] + f(i+1, 1, c-1, prices, dp));
            int skip = 0 + f(i+1, 0, c, prices, dp);
            profit = max(Sell, skip);
        }
        return dp[i][buy][c] = profit;
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
            vector<vector<vector<int>>> dp(n + 1, 
         vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int i = n-1; i >= 0; i--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int c = 1; c <= k; c++) {
                    int profit = 0;
                    if(buy == 1)
                    {
                        int Buy = -prices[i] + dp[i+1][0][c];
                        int skip = 0 + dp[i+1][1][c];
                        profit = max(Buy, skip);
                    } 
                    else
                    {
                        int Sell = prices[i] + dp[i+1][1][c-1];
                        int skip = 0 + dp[i+1][0][c];
                        profit = max(Sell, skip);
                    }
                    dp[i][buy][c] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};



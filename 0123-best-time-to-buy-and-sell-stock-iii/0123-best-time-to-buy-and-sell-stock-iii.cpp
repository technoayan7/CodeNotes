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
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, 
         vector<vector<int>>(3, vector<int>(3, -1)));
        return f(0, 1, 2, prices, dp);
    }
};



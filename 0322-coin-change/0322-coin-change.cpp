class Solution {
public:
    int f(int ind, vector<int> &coins, int amt, vector<vector<int>> &dp) {
        if(ind == 0){
            if(amt%coins[0] == 0) return amt/coins[0];
            else return 1e9;
        }
        if(dp[ind][amt] != -1) return dp[ind][amt];
        
        int notTake = 0 + f(ind-1, coins, amt, dp);
        int take = INT_MAX;
        if(coins[ind] <= amt) {
            take = 1 + f(ind, coins, amt - coins[ind], dp);
        }
        return dp[ind][amt] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1,-1));
        int ans = f(n-1, coins, amount, dp);
        if(ans >= 1e9) return -1;
        return ans;
    }
};
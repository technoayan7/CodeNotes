class Solution {
public:
    int f(int ind, int prev_ind, vector<int>& arr, int n, vector<vector<int>> &dp){

        if(ind == n) return 0;

        if(dp[ind][prev_ind+1] != -1) return dp[ind][prev_ind+1];

        int notTake = 0 + f(ind + 1, prev_ind, arr, n, dp);
        int take = 0;
        if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
            take = 1 + f(ind + 1, ind, arr, n, dp);
        }

        return dp[ind][prev_ind+1] = max(notTake, take);
    }
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return f(0, -1, arr, n, dp);
    }
};
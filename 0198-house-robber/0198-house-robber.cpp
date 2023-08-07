class Solution {
public:
    int rob(vector<int>& A, vector<int>& dp, int i) {
        if(i >= size(A)) return 0;
        if(dp[i] != -1) return dp[i];
        int notTake = 0 + rob(A, dp, i+1);
        int take = A[i] + rob(A, dp, i+2);
        return dp[i] = max(notTake, take);
    }
    
    int rob(vector<int>& A) {
        vector<int> dp(size(A),-1);
        return rob(A, dp, 0);
    }
};
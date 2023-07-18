class Solution {
public:
    int mod = (int)1e9+7;
    int numDistinct(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<n+1;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1])
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][m];
    }
};
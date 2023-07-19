class Solution {
public:
    int f(int i, int j, string& p, string& t, vector<vector<int>>& dp){
        if(i==0 && j==0) return true;
        if(i==0 && j>0) return false;
        if(j==0 && i>0) {
            for(int ii=1;ii<=i;ii++){
                if(p[ii-1]!='*') return false;
            }
            return true;
        }  

        if(dp[i][j]!=-1) return dp[i][j];

        if(p[i-1] == t[j-1] || p[i-1]=='?')
            return dp[i][j] = f(i-1, j-1, p, t, dp);
        else if(p[i-1]=='*')
            return dp[i][j] = f(i-1, j, p, t, dp) | f(i, j-1, p, t, dp);
        else 
            return dp[i][j] = false;
    }
    
    bool isMatch(string t, string p) {
        int n = p.size(), m = t.size();
       vector<vector<bool>> dp(n+1, vector<bool> (m+1, false));

       //Base Cases
       dp[0][0] = true;
       for (int j = 1; j <= m; j++) {
          dp[0][j] = false;
       }
       for(int i=1;i<=n;i++) {
          bool flag = true;
          for(int ii=1;ii<=i;ii++){
             if(p[ii-1]!='*') {
                flag = false;
                break;
             }
          }
          dp[i][0] = flag;
       }

       for(int i=1;i<=n;i++) {
          for(int j=1;j<=m;j++) {
             if(p[i-1] == t[j-1] || p[i-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
             }
             else if(p[i-1] == '*') {
                dp[i][j] = dp[i-1][j] | dp[i][j-1];
             } else {
               dp[i][j] = false;
             }
          }
       }
       return dp[n][m];
    }
};
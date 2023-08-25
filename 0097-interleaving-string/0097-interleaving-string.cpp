class Solution {
public:
    bool c(int i, int j, int k, string &s1, string &s2, string &s3,
    vector<vector<vector<int>>>&dp){
        
        if(k == s3.size()) {
            if(j==s2.size() && i==s1.size()) return true;
            else return false;
        }
        
        if(dp[i][j][k] != -1) return dp[i][j][k];
        char c1='*', c2='*';
        
        if(i < s1.size()) c1=s1[i];
        if(j < s2.size()) c2=s2[j];
        bool ans = false;
        
        if(c1==s3[k])ans |= c(i+1, j, k+1, s1, s2, s3, dp);
        if(c2==s3[k])ans |= c(i, j+1, k+1, s1, s2, s3, dp);
        return dp[i][j][k] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>>dp(s1.size()+1,vector<vector<int>>(s2.size()+1,vector<int>(s3.size(),-1)));
        return c(0,0,0,s1,s2,s3,dp);
    }
};
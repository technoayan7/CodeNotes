class Solution {
public:
    int lcs(string& s, int i, int j, vector<vector<int>>& dp){
        if(i > j) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j])
            return dp[i][j] = lcs(s, i+1, j-1, dp);
        else 
            return dp[i][j] = 0;   
    }
    
    int countSubstrings(string s) {
        int cnt = 0, n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int i=0; i<n; i++) {
            for(int j=i; j<n; j++) {
                cnt += lcs(s, i, j, dp);
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        int n = s.size();
        vector<int> dp(n + 1, n);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (auto word : dict) {
                int len = word.size();
                if (i >= len && s.substr(i - len, len) == word) {
                    dp[i] = min(dp[i], dp[i - len]);
                    cout<<s.substr(i - len, len)<<endl;
                }
            }
            dp[i] = min(dp[i], dp[i - 1] + 1);
            cout<<dp[i]<<endl;
        }
        return dp[n];
    }
};
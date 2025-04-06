class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<int> dp(n, 1), hash(n, -1);
        int mx = 1;
        int lastIndex = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] % arr[j] == 0 and 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
                if(dp[i] > mx) {
                    mx = dp[i];
                    lastIndex = i;
                }
            }
        }
        vector<int> ans;
        while (lastIndex != -1) {
            ans.push_back(arr[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        return ans;
    }
};
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int f(int ind, int coins[], int amt, vector<vector<long long int>> &dp) {
        if(ind == 0) {
            return amt%coins[0] == 0;
        }
        if(dp[ind][amt] != -1) return dp[ind][amt];
        
        long long int notTake = 0 + f(ind-1, coins, amt, dp);
        long long int take = 0;
        if(coins[ind] <= amt) {
            take = f(ind, coins, amt - coins[ind], dp);
        }
        return dp[ind][amt] = take + notTake;
    }
    long long int count(int coins[], int n, int sum) {
        vector<vector<long long int>> dp(n, vector<long long int> (sum+1,-1));
        return f(n-1, coins, sum, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
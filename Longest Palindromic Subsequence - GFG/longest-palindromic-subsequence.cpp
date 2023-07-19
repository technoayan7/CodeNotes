//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  int f(string& s1, string& s2, int ind1, int ind2,  vector<vector<int>>& dp){
        if(ind1<0 || ind2<0) return 0;
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];

        if(s1[ind1] == s2[ind2])
            return dp[ind1][ind2] = 1 + f(s1,s2,ind1-1,ind2-1,dp);
        else 
            return dp[ind1][ind2] = 0 + max(f(s1,s2,ind1,ind2-1,dp),f(s1,s2,ind1-1,ind2,dp));
    }
    int longestPalinSubseq(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        int n=s1.size();
        int m=s2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(s1,s2,n-1,m-1,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
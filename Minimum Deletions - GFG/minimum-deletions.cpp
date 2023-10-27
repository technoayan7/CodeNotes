//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int dp[1001][1001];
    int dfs(int i, int j, string& s){
        if(i>=j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s[i]==s[j])
            return dp[i][j]=dfs(i+1,j-1,s);
        else
            return dp[i][j]= min(1+dfs(i+1,j,s),1+dfs(i,j-1,s));
    }
    int minimumNumberOfDeletions(string S) { 
        // code here
        memset(dp,-1,sizeof(dp));
        return dfs(0,S.length()-1,S);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends
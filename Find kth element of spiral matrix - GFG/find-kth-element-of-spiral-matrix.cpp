//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
        vector<int> result;
        int left = 0, right = m - 1, top = 0, bottom = n - 1;

        while(top<=bottom && left<=right) {
            for (int j = left; j <= right; j++)
                result.push_back(a[top][j]);
            top++;

            for (int i = top; i <= bottom; i++)
                result.push_back(a[i][right]);
            right--;

            for (int j = right; j >= left; j--)
                result.push_back(a[bottom][j]);
            bottom--;

            for (int i = bottom; i >= top; i--)
                result.push_back(a[i][left]);
            left++;
        }
        return result[k-1];
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int a[], int n) 
    { 
        for(int i=0;i<n;) {
            if(a[i]>0 and a[i]<=n and a[i]!=a[a[i]-1]) {
                swap(a[i], a[a[i]-1]); // 1 jayega zero index pe 2 jayega 1 pe
            }
            else
                i++;
        }
        int i=0;
        for(i=0;i<n;i++) {
            if(a[i]!=i+1){
                break;
            }
        }
        return i+1;
    } 
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    int freq[26]={0};
            queue<char>q;
            string ans="";
            for (int i = 0; i < A.size(); i++) {
                q.push(A[i]);
                freq[A[i]-'a']++;
                
                while(!q.empty()){
                    if(freq[q.front()-'a']==1){
                        ans+=q.front();
                        break;
                    }
                    else
                    q.pop();
                }
                if(q.empty()) ans+='#';
            }
                return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
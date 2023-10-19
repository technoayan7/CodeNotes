//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    int vis[V] = {0}; 
        vis[0] = 1; 
        queue<int> q;
        q.push(0); 
        vector<int> bfs; 
        int l = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int node = q.front(); 
                q.pop(); 
                if(node == X) return l;
                for(auto it : adj[node]) {
                    if(!vis[it]) {
                        vis[it] = 1; 
                        q.push(it); 
                    }
                }
            }
            l++;
        }
        return -1; 
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends
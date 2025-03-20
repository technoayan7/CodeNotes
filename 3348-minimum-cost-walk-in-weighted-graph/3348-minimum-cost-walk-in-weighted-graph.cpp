class Solution {
public:
    void dfs(int node, vector<vector<int>> &gr,vector<int> &vis,int compNumb,unordered_map<int,int> &nodeToComp){
        vis[node]=1;
        nodeToComp[node]=compNumb;
        for (auto it: gr[node]){
            if(!vis[it])
              dfs(it,gr,vis,compNumb,nodeToComp);
        }
    }
    
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        int z = edges.size();
        vector<vector<int>> gr(n, vector<int>(0));
        for (int i=0;i<z;i++){
            int u = edges[i][0], v = edges[i][1];
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        unordered_map<int,int> nodeToComp;
        int compNumb=1;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,gr,vis,compNumb,nodeToComp);
                compNumb++;
            }
        }

        vector<int> compAndScore(n,pow(2,21)-1);
        for(int i=0;i<z;i++){
            int u = edges[i][0], v = edges[i][1];
            int uComp = nodeToComp[u];
            compAndScore[uComp] &= edges[i][2];
        }

        vector<int> ans;
        int q=query.size();
        for(int i=0;i<q;i++){
            int u = query[i][0], v = query[i][1];
            if(u == v){
                ans.push_back(0);
            }
            else if(nodeToComp[u] == nodeToComp[v]){
                ans.push_back(compAndScore[nodeToComp[u]]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
        
    }
};
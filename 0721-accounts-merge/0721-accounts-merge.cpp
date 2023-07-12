class DisjointSet {
    vector<int> rank, parent, size; 
public: 
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }

    int findParent(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findParent(parent[node]); 
    }

    void unionByRank(int u, int v) {
        int a = findParent(u); 
        int b = findParent(v);
         
        if(a == b) return; 
        if(rank[a] < rank[b]) {
            parent[a] = b; 
        }
        else if(rank[b] < rank[a]) {
            parent[b] = a; 
        }
        else {
            parent[b] = a; 
            rank[a]++; 
        }
    }

    void unionBySize(int u, int v) {
        int a = findParent(u); 
        int b = findParent(v); 
        if(a == b) return; 
        if(size[a] < size[b]) {
            parent[a] = b; 
            size[b] += size[a]; 
        }
        else {
            parent[b] = a;
            size[a] += size[b]; 
        }
    }
}; 

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        map<string,int> mp;
        DisjointSet dsu(n);
        vector<vector<string>> ans;
        
        for(int i=0;i<n;i++) {
            for(int j=1;j<accounts[i].size();j++) {
                string mail = accounts[i][j];
                if(mp.find(mail)==mp.end()) 
                    mp[mail] = i;
                else 
                    dsu.unionBySize(i,mp[mail]);
            }
        }
        
        vector<string> mergedMail[n];
        for(auto it: mp) {
            string mail = it.first;
            int node = dsu.findParent(it.second);
            mergedMail[node].push_back(mail);
        }
        
        for(int i=0;i<n;i++) {
            if(mergedMail[i].size() == 0) continue;
            sort(mergedMail[i].begin(), mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }    
        return ans;
    }
};
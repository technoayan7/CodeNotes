class Solution {
    public:
        vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        while(!q.empty()){
            root=q.front().first;
            int vert=q.front().second.first;
            int lvl=q.front().second.second;
            q.pop();
            mp[vert][lvl].insert(root->val);
            if(root->left) q.push({root->left, {vert-1, lvl+1}});
            if(root->right) q.push({root->right, {vert+1, lvl+1}});
        }
        vector<vector<int>>ans;
        for(auto it: mp){
            vector<int>v;
            for(auto it1: it.second){
                v.insert(v.end(), it1.second.begin(), it1.second.end());
            }
            ans.push_back(v);
        }
        return ans;
    }
};
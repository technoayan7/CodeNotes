class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int k = 0;
        while(!q.empty()) {
            int n = q.size();
            vector<int> ans;
            for(int i=0;i<n;i++) {
                auto it = q.front();
                q.pop();
                ans.push_back(it->val);
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            k = ans[0];
        }
        return k;
    }
};
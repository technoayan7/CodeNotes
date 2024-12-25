class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()) {
            int n = q.size();
            int mx = INT_MIN;
            while(n--) {
                TreeNode* node = q.front();
                mx = max(mx, node->val);
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};
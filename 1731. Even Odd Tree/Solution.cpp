class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = 1;
        while(!q.empty()) {
            vector<int> ans;
            int n = q.size();
            for(int i=0;i<n;i++) {
                auto it = q.front();
                q.pop();
                if(flag==1) {
                    if(it->val%2==0) return false;
                }
                if(flag==0) {
                    if(it->val%2) return false;
                }
                ans.push_back(it->val);
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }
            if(flag == 1) {
                for(int i=0;i<ans.size()-1;i++) {
                    if(ans[i] >= ans[i+1]) return false;
                }
            }
            else {
                for(int i=0;i<ans.size()-1;i++) {
                    if(ans[i] <= ans[i+1]) return false;
                }
            }
            flag = !flag;
        }
        return true;
    }
};
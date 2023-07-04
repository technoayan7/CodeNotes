class Solution {
public:
    unordered_map<int,int> mp;
    void helper(vector<int>&arr,TreeNode* root)
    {
        if(root==NULL) {
            return ;
        }
        helper(arr,root->left);
        arr.push_back(root->val);
        mp[root->val]++;
        helper(arr,root->right);
    }
    
    bool findTarget(TreeNode* root, int k) 
    {
        vector<int>arr;
        helper(arr,root);
        int n = arr.size();
        if(n==1) return false;
        for(int i=0; i<n; i++){
            int x = k - arr[i];
            if(mp.find(x)!=mp.end() and x!=arr[i]) {
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    TreeNode* solve(int left , int right , vector<int>&ans ){
        if(left>right) return nullptr;
        int mid = left + (right-left)/2;
        
        TreeNode* root = new TreeNode(ans[mid]);
        root->left = solve(left , mid-1 ,ans);
        root->right= solve(mid+1 , right , ans);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0,nums.size()-1,nums);
    }
};
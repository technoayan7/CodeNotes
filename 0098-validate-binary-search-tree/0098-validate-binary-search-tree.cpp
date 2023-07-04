class Solution {
public:
    bool bst(TreeNode* root, long mi, long mx) {
        if(root == NULL) return true;
        if(root->val >= mx  || root->val <= mi) return false;
        bool left = bst(root->left, mi, root->val);
        bool right = bst(root->right, root->val, mx);
        return left && right;
    }
    bool isValidBST(TreeNode* root) {
        long mi = LONG_MIN;	
        long mx = LONG_MAX;	
        return bst(root, mi, mx); 
    }
    
};
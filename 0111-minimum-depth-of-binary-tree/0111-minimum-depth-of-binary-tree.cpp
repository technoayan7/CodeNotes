class Solution{
  public:
    int minDepth(TreeNode *root) {
        if(root==NULL) return 0;
        int lh = minDepth(root->left);
        int rh = minDepth(root->right);
        if(lh==0 || rh==0) return 1 + max(lh,rh);
        else return 1 + min(lh,rh);
    }
};
class Solution {
public:
    bool checkTree(TreeNode* root) {
        if(root==NULL) return 1;
        if(root->left==NULL && root->right==NULL) return 1;
        int sum = 0;
        if(root->left!=NULL) sum+=root->left->val;
        if(root->right!=NULL) sum+=root->right->val;
        
        return (root->val==sum) && checkTree(root->left) && checkTree(root->right);
        
    }
};
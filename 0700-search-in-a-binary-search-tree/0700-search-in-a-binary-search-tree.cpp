class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int x) {
        if(root==NULL) return NULL;
        if(root->val==x) {
            return root;
        }
        else if(root->val > x) return searchBST(root->left, x);
        else return searchBST(root->right, x);
    }
};
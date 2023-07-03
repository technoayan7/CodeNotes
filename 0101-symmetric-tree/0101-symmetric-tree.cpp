class Solution {
public:
    bool helper(TreeNode* root1, TreeNode* root2)
    {
        if(root1==NULL and root2==NULL) return true;
        if(root1==NULL || root2==NULL) return false;
        bool equal1 = helper(root1->left, root2->right);
        bool equal2 = helper(root1->right, root2->left);
        bool equal3 = root1->val == root2->val;
        
        return (equal1 and equal2 and equal3);
    }
    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
};
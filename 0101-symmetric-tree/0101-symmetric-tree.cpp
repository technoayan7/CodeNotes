
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        return check(root, root);
    }
    bool check(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL || root2==NULL) return root1==root2;
        if(root1->val != root2->val) return false;
        bool f1 = check(root1->left, root2->right);
        bool f2 = check(root1->right, root2->left);
        return f1&f2;
    }
};
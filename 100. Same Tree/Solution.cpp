class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL || q==NULL) {
            return (p==q);
        }
        bool equal = (p->val == q->val);
        bool left = isSameTree(p->left,q->left);
        bool right = isSameTree(p->right,q->right);
        if(left and right and equal)
            return true;
        else
            return false;
    }
};
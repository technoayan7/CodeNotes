
class Solution {
public:
    vector<int> v1,v2;
    void preorder1(TreeNode* root) {
        if (root == NULL) return;

        if (!root->left && !root->right)
            v1.push_back(root->val);

        preorder1(root->left);
        preorder1(root->right);
    }
    void preorder2(TreeNode* root) {
        if (root == NULL) return;

        if (!root->left && !root->right)
            v2.push_back(root->val);

        preorder2(root->left);
        preorder2(root->right);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        preorder1(root1);
        preorder2(root2);
        return v1==v2;
    }
};
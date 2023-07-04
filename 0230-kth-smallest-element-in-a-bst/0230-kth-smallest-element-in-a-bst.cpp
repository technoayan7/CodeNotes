class Solution {
public:
    int ans = -1, c = 1;
    void inorder(TreeNode* root, int k){
        if(root== NULL){
            return;
        }
        else {
            inorder(root->left, k);
            if(c==k) ans = root->val;
            c++;
            inorder(root->right, k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};
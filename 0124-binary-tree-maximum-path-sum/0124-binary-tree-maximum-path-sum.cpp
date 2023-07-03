
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        height(root, maxi);
        return maxi;
    }
    int height(TreeNode* root, int &maxi) {
        if(root == NULL) return 0;
        int leftsum = max(0, height(root->left, maxi));
        int rightsum = max(0, height(root->right, maxi));
        maxi = max(maxi, root->val + leftsum + rightsum);
        return root->val + max(leftsum, rightsum);
    }
};
class Solution {
public:
    TreeNode* CTree(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int> &mp)
    {
        if((preStart > preEnd) || (inStart > inEnd)) {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[preStart]);
        int mid = mp[root -> val]; // positon of root in inorder
        int x = mid - inStart; // left side of inorder
        
        root->left = CTree(preorder, preStart + 1, preStart + x, inorder, inStart, mid - 1, mp);
        root->right = CTree(preorder, preStart + x + 1, preEnd, inorder, mid + 1, inEnd, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart = 0, preEnd = preorder.size() - 1;
        int inStart = 0, inEnd = inorder.size() - 1;

        map < int, int > mp;
        for (int i = inStart; i <= inEnd; i++) {
            mp[inorder[i]] = i;
        }

        return CTree(preorder, preStart, preEnd, inorder, inStart, inEnd, mp);
    }
};
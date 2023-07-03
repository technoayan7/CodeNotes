class Solution {
public:
    TreeNode* CTree(vector<int>& postorder, int postStart, int postEnd, 
                    vector<int>& inorder, int inStart, int inEnd, map<int,int> &mp)
    {
        if((postStart > postEnd) || (inStart > inEnd)) 
        {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int mid = mp[root -> val]; // positon of root in inorder
        int x = mid - inStart; // left side of inorder
        
        root->left = CTree(postorder, postStart, postStart + x - 1, inorder, inStart, mid - 1, mp);
        root->right = CTree(postorder, postStart + x, postEnd-1, inorder, mid + 1, inEnd, mp);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postStart = 0, postEnd = postorder.size() - 1;
        int inStart = 0, inEnd = inorder.size() - 1;

        map < int, int > mp;
        for (int i = inStart; i <= inEnd; i++) {
            mp[inorder[i]] = i;
        }

        return CTree(postorder, postStart, postEnd, inorder, inStart, inEnd, mp);
    }
};
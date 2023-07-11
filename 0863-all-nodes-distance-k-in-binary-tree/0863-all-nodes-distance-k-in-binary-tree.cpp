class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        unordered_map<TreeNode*,TreeNode*> parent;
        q.push(root);

        while(!q.empty()){
            TreeNode*front=q.front();
            q.pop();
            if(front->left){
                parent[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                parent[front->right] = front;
                q.push(front->right);
            }
        }

        unordered_map<TreeNode*,bool> visited;
        q.push(target);
        visited[target]=true;
        int cnt=0;
        while(!q.empty()){
            if(cnt==k) break;
            cnt++;
            int size=q.size();
            for(int i=0;i<size;i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left  &&  !visited[node->left]){
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right  &&  !visited[node->right]){
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parent[node]  &&  !visited[ parent[node] ]){
                    q.push( parent[node] );
                    visited[parent[node]]=true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back( node->val );
        }
        return ans;
    }
};


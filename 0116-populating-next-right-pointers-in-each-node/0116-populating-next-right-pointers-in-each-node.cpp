class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*> q;
        q.push(root);        
        while(!q.empty()) {
            Node* rightNode = NULL;
            int n = q.size();
            while(n--) { 
                auto cur = q.front(); 
                q.pop();     
                cur -> next = rightNode;
                rightNode = cur;   
                if(cur->right != NULL)            
                    q.push(cur -> right),           
                    q.push(cur -> left);              
            }
        }
        return root;
    }
};
class Solution {
public:
    bool dfs(vector<vector<char>>& board, string word,int n,int m,int i,int j,int index) { 
        
        if(i<0 || j<0 || i>=n || j>=m || board[i][j] != word[index])
            return false;

        if(index == word.size()-1) return true;
        char temp = board[i][j]; 
        board[i][j] = '*';
        bool ans1 = dfs(board,word,n,m,i+1,j,index+1);
        bool ans2 = dfs(board,word,n,m,i,j+1,index+1);
        bool ans3 = dfs(board,word,n,m,i-1,j,index+1);
        bool ans4 = dfs(board,word,n,m,i,j-1,index+1);
        board[i][j] = temp;
        return ans1 || ans2 || ans3 || ans4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j] == word[0] && dfs(board,word,n,m,i,j,0)) return true;
            }
        }
        return false;
    }
};
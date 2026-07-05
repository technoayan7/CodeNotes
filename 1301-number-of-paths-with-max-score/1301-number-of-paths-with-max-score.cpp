class Solution {
public:
    int mod = 1e9+7;
    int dp[105][105];
    int path[105][105];

    int max_score(int i,int j,vector<string>& board){
        if(i == 0 && j == 0) return dp[i][j] = 0;
        if(i < 0 || j < 0 || board[i][j] == 'X') return INT_MIN;  

        if(dp[i][j] != -1) return dp[i][j];

        int up = max_score(i-1,j,board);
        int left = max_score(i,j-1,board);
        int up_left = max_score(i-1,j-1,board);

        int  ans = (board[i][j]-'0' + max({up, left, up_left})%mod)%mod;
        return dp[i][j] = ans;
    }

    int tot_path(int i, int j,vector<string> &board){
        if(i == 0 && j == 0) return 1;
    
        if(i < 0 || j < 0 || board[i][j] == 'X') return 0;  

        if(path[i][j] != -1) return path[i][j];

        int up = 0, left = 0, up_left = 0, ans = 0;

        if(i-1 >= 0 && dp[i-1][j]+board[i][j]-'0' == dp[i][j])
            up = tot_path(i-1,j,board) % mod;
        
        if(j-1 >= 0 && dp[i][j-1]+board[i][j]-'0' == dp[i][j])
            left = tot_path(i,j-1,board) % mod;
        
        if(i-1 >= 0  && j-1>=0 && dp[i-1][j-1]+board[i][j]-'0' == dp[i][j]) 
            up_left = tot_path(i-1,j-1,board) % mod;

        return path[i][j] = ((up%mod + left%mod)%mod + up_left)%mod;
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        
        memset(dp,-1,sizeof dp);
        memset(path,-1,sizeof path);

        vector<int> ans(2);
        int m = board.size(), n = board[0].size();
        board[m-1][n-1]='0';

        long long score = max_score(m-1,n-1,board);
        long long path = tot_path(m-1,n-1,board);
      
        ans[0] = score < 0 ? 0 : score;
        ans[1] = score < 0 ? 0 : path;
        return ans;
    }
};
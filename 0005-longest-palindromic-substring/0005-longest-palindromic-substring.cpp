class Solution {
public:
    string longestPalindrome(string s) {
        
        int n = s.length();
        int low,high;
        
        int st=0, len=1; 
        
        for(int i=1;i<n;i++){
            
            //even case
            low = i;
            high = i-1;
            while(low>=0 && high<n && s[low]==s[high]){
                
                if(high-low+1 > len){
                    st = low;
                    len = high-low+1;
                }
                low--;high++;
            }
            
            //odd case
            low = i-1;
            high = i+1;
            while(low>=0 && high<n && s[low]==s[high]){
                
                if(high-low+1 > len){
                    st = low;
                    len = high-low+1;
                }
                low--;
                high++;
            }
            
            
        }
        
        return s.substr(st,len);
       
    }
};


// class Solution {
// private: 
//     bool solve(vector<vector<bool>> &dp, int i, int j, string &s){
//         if(i == j){
//             return dp[i][j] = true;
//         }
//         if(j-i == 1){
//             if(s[i] == s[j]){
//                 return dp[i][j] = true;
//             }
//             else{
//                 return dp[i][j] = false;
//             }
//         }
//         if(s[i] == s[j] && dp[i+1][j-1] == true){
//             return dp[i][j] = true;
//         } else {
//             return dp[i][j] = false;
//         }
//     }
// public:
//     string longestPalindrome(string s) {
//         int n = s.size();
//         int startIndex = 0; int maxlen = 0;
//         vector<vector<bool>> dp(n, vector<bool>(n, false));
//         for(int g=0; g<n; g++){
//             for(int i=0, j=g; j<n; i++, j++){
//                 solve(dp, i, j, s);
//                 if(dp[i][j] == true){
//                     if(j-i+1 > maxlen){
//                         startIndex = i;
//                         maxlen = j-i+1;
//                     }
//                 }
//             }
//         }
//         return s.substr(startIndex, maxlen);
//     }
// };
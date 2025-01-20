class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();

        unordered_map<int, int> rowcount, colcount; 
        unordered_map<int,pair<int,int>>mp;

        for(int i=0;i<m;++i){
            for(int j=0;j<n;++j){
                mp[mat[i][j]]={i,j}; //store the coordinates of each number in the matrix
            }
        }

        for(int i=0;i<arr.size();++i){
            int row=mp[arr[i]].first;
            int col=mp[arr[i]].second;
            
            // increment the row and column count for each occurrence
            ++rowcount[row];
            ++colcount[col];
            
            // if any row or column has all the numbers, return the current index          
            if(rowcount[row]==n || colcount[col]==m) return i;
        }      
        return -1;
    }
};
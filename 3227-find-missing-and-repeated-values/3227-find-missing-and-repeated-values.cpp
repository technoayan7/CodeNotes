class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        set<int> st;
        int a, b;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(st.count(grid[i][j])) {
                    a = grid[i][j];
                }
                else {
                    st.insert(grid[i][j]);
                }
            }
        }
        int ct = 1;
        for(auto it: st) {
            if(ct == it){
                ct++;
            }
            else {
                b = ct;
                break;
            }
        }
        return {a,b};
    }
};
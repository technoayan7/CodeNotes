class Solution {
public:
    int findJudge(int n, vector<vector<int>>& a) {
        vector<int> v(n+2, 0);
        for(auto it: a) {
            v[it[0]]--;
            v[it[1]]++;
        }
        for(int i=1;i<=n;i++) {
            if(v[i]==n-1) return i;
        }
        return -1;
    }
};
class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int zero = 0, one = 0;
        for(int i=0;i<n;i++) {
            if(s[i] == '1') one++;
        }
        int mx = 0;
        for(int i=0;i<n-1;i++) {
            if(s[i] == '0') zero++;
            else one--;
            mx = max(mx, zero+one);
        }
        return mx;
    }
};
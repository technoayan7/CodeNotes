class Solution {
public:
    int countHomogenous(string s) {
        int n = s.size();
        int i = 0,j = 0;
        long long cnt = 0;
        int mod = 1e9 + 7;
        while (j < n) {
            if (s[i] != s[j]) {
                i = j;
            }
            cnt = (cnt + (j - i + 1)) % mod;
            j++;
        }
        return cnt;
    }
};
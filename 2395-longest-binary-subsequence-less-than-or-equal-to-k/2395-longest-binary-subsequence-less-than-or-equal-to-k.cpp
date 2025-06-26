class Solution {
public:
    bool solve(string str, int k) {
        long long val = 0;
        int p = 0;
        for (int i = str.size() - 1; i >= 0; i--) {
            val += (str[i] - '0') * pow(2, p);
            p++;
            if (p >= 32) return false;
        }
        return val <= k;
    }
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int zeros = 0, ones = 0;
        for (auto it : s) {
            if (it == '0')
                zeros++;
        }
        int len = zeros;
        string str = "";
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '0') {
                str = s[i] + str;
            } else {
                str = s[i] + str;
                if (solve(str, k)) {
                    len++;
                }
            }
        }
        return len;
    }
};

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int low, high;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            low = i;
            high = i + 1;
            while (low >= 0 and high < n and s[low] == s[high]) {
                low--;
                high++;
                cnt++;
            }
            low = i;
            high = i;
            while (low >= 0 and high < n and s[low] == s[high]) {
                low--;
                high++;
                cnt++;
            }
        }
        return cnt;
    }
};
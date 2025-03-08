class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l = 0, r = 0;
        int ct = 0, ans = INT_MAX;
        int n = blocks.length();

        for (r = 0; r < k; r++) {
            if (blocks[r] == 'W') {
                ct++;
            }
        }
        ans = ct;

        while (r < n) {
            if (blocks[l] == 'W') ct--;
            if (blocks[r] == 'W') ct++;
            ans = min(ans, ct);
            l++;
            r++;
        }
        return ans;
    }
};
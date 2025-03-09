class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), cnt = 1, res = 0;
        for (int i = 0; i < n + k - 2; i++) {
            if (colors[i % n] != colors[(i + 1) % n]) cnt++;
            else cnt = 1;
            if (cnt >= k) {
                res += 1;
            }
        }
        return res;
    }
};
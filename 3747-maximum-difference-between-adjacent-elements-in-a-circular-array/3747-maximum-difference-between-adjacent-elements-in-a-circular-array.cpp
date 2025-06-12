class Solution {
public:
    int maxAdjacentDistance(vector<int>& a) {
        int n = a.size();
        int mx = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            mx = max(mx, abs(a[i] - a[j]));
        }
        return mx;
    }
};